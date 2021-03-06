#include "../mbed/mbed.h"
#include "ThrottleBodyCtrl.h"
#include "utils.h"
#include "PwmIn.h"

#define TEST_BUILD true
#define TEST_TX false


const int ICE_REV_LIMIT = 5000;


Serial pc(USBTX, USBRX); // (Talk to PC)

AnalogIn att_ch1(p20);  // (Input) Attenuator signal Channel 1
AnalogIn att_ch2(p19);  // (Input) Attenuator signal Channel 2
AnalogOut yasa(p18); // (Output) YASA MC voltage
Serial mc(p28, p27); // (Input/Output) Motor Controller serial line
PwmOut mc2(p21);    // (Output) PWM line to new Motor Controller

LocalFileSystem local("local");

#if (TEST_BUILD == true && TEST_TX == false)
AnalogIn test_engine_rpm(p16);  // (Input) Fake Engine RPM signal
#endif

CAN vnet(p30, p29); // (Input/Output) Vehicle CAN network lines
CANMessage cmsg; // Stores most recent, highest priority CAN message.
float yasa_rampup=0;

DigitalIn toggle_fwd(p5);
DigitalIn toggle_bwd(p6);
DigitalOut fwd_enable(p7);
DigitalOut bwd_enable(p8);
DigitalOut l1(LED1);
DigitalOut l2(LED2);
PwmIn xout(p15);

int FWD_ON=0;
int BWD_ON=0;
bool fwd=false;
bool bwd=false;
bool waitforLOW_fwd=true;
bool reseted_fwd=false;
bool waitforLOW_bwd=true;
bool reseted_bwd=false;
int cycle=0;
int toggle_noise_count_fwd=0;
int toggle_noise_count_bwd=0;

int main() {
  
    int test_rpm = 1;
   
    while (1) 
    {
     
           unsigned long long ice_rpm = 0;
           float waitDelay = 0.01;
           float avg_att = 0.00;
           float last_att = -1.00;
    //time_t last = 0;
    //time_t now = time(NULL);
    
            mc2.period_ms(20);
            int test_rpm = 0;  
            
            #if (TEST_BUILD == true && TEST_TX == true)
        //
        utils::set_leds(false, true, false, true);
        wait(1.0);
        unsigned long long n = test_rpm;
        char * adr = new char [2];
        char first = (n >> 8) & 0xFF;
        char second = n & 0xFF; 
        adr[0] = second;
        adr[1] = first;

        vnet.write(CANMessage(0x610, adr));
        
        if (test_rpm > ICE_REV_LIMIT) { 
            utils::set_leds(true, true, true, true);
        } else {
            utils::set_leds(false, false, false, false);
        }
        test_rpm += 1000;
        if (test_rpm > 10000) {
            test_rpm = 0;
        }
        wait(1.0);
        continue;
#endif
        
        if (vnet.read(cmsg))
         {
            if (cmsg.id == 0x610) 
            {
                char first_byte = cmsg.data[1];
                char second_byte = cmsg.data[0];

                ice_rpm = first_byte;
                ice_rpm = (ice_rpm << 8);
                ice_rpm = ice_rpm | second_byte;
                utils::set_leds(true, false, false, true);
            }
        }
        
        
          cycle++;
          pc.printf("\n Cycle=%d ",cycle);
//        pc.printf("\t Status_fwd=");fwd?pc.printf("true"):pc.printf("false");
//        pc.printf("\t Status_bwd=");bwd?pc.printf("true"):pc.printf("false");
//        pc.printf("\t Status_waitforLOW_FWD=");waitforLOW_fwd?pc.printf("true"):pc.printf("false");
//        pc.printf("\t Status_waitforLOW_BWD=");waitforLOW_bwd?pc.printf("true"):pc.printf("false");
//        pc.printf("\t Status_reseted_FWD=");reseted_fwd?pc.printf("true"):pc.printf("false");
//        pc.printf("\t Status_reseted_BWD=");reseted_bwd?pc.printf("true"):pc.printf("false");
          //toggle_fwd==1?pc.printf("\t toggle_fwd=3.3"):pc.printf("toggle_bwd=0");
          //toggle_bwd==1?pc.printf("\t toggle_bwd=3.3"):pc.printf("toggle_fwd=0");
          if(waitforLOW_fwd)
        {
            if(!toggle_fwd)
            {
                reseted_fwd=true;
                waitforLOW_fwd=false;
            }
        }
        else if(waitforLOW_bwd)
        {
            if(!toggle_bwd)
            {
                reseted_bwd=true;
                waitforLOW_bwd=false;
            }
        }
        
        
        if(fwd&&!bwd)
        {
            fwd_enable=1;
            bwd_enable=0;
            l1=1;
            l2=0;
        }
        else if(bwd&&!fwd&&test_rpm==0)
        {
            fwd_enable=0;
            bwd_enable=1;
            l1=0;
            l2=1;
        }
        else if(!bwd&&!fwd)
        {
            fwd_enable=0;
            bwd_enable=0;
            l1=0;
            l2=0;
        }
        
        if(toggle_fwd)
        {
            toggle_noise_count_bwd=0;
            toggle_noise_count_fwd++;
            waitforLOW_fwd=true;
            if(reseted_fwd&&toggle_noise_count_fwd>3)
            {
            if(!fwd&&!bwd&&reseted_fwd)
            {
                fwd=true;
                bwd=false;
                reseted_fwd=false;
            }
            else if(fwd&&!bwd&&reseted_fwd)
            {
                fwd=false;
                bwd=false;
                reseted_fwd=false;
            }
            else if (!fwd&&bwd&&reseted_fwd)
            {
                fwd=false;
                bwd=false;
                reseted_fwd=false;
            }
            }
        }
        else if(toggle_bwd)
        {
            toggle_noise_count_fwd=0;
            toggle_noise_count_bwd++;
            waitforLOW_bwd=true;
            if(reseted_bwd&&toggle_noise_count_bwd>3)
            {
            if(!fwd&&!bwd&&reseted_bwd)
            {
                fwd=false;
                bwd=true;
                reseted_bwd=false;
            }
            else if(!fwd&&bwd&&reseted_bwd)
            {
                fwd=false;
                bwd=false;
                reseted_bwd=false;
            }
            else if (fwd&&!bwd&&reseted_bwd)
            {
                fwd=false;
                bwd=false;
                reseted_bwd=false;
            }
            
            }
        }else
        {
            toggle_noise_count_fwd=0;
            toggle_noise_count_bwd=0;
        }
        
          
        // Set the Yasa MC to match the attenuator
        // TODO: check for huge difference
        avg_att = (att_ch1 + att_ch2) / 2.00;
        
        last_att = avg_att;
        
        int target = int(avg_att * 2000.00 + 300);
        if (target > 2500) {
            target = 2500;
        } else if (target < 0) {
            target = 0;
        }
            
        mc2.pulsewidth_us(target);
        
       if (ice_rpm >= ICE_REV_LIMIT) 
       {
#if (TEST_BUILD == true && TEST_TX == false)
            utils::set_leds(true, true, true, true);
#endif
            yasa = 0;
       } else 
            {
#if (TEST_BUILD == true && TEST_TX == false)
            utils::set_leds(false, false, false, false);
#endif            
            //ramp_up
                if(avg_att>yasa_rampup)
                {
                    yasa_rampup=yasa_rampup+.01f;
                    yasa=yasa_rampup;
                }
                else
                {   
                yasa = avg_att;
                yasa_rampup=avg_att;
                }
            
             }
        
        
        
        wait(waitDelay);

        
    }

        
    
}