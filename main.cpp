#include "../mbed/mbed.h"
#include "ThrottleBodyCtrl.h"
#include "utils.h"


#define TEST_BUILD true
#define TEST_TX false

const int ICE_REV_LIMIT = 13000;

AnalogIn att_ch1(p20);  // (Input) Attenuator signal Channel 1
AnalogIn att_ch2(p19);  // (Input) Attenuator signal Channel 2
AnalogOut yasa(p18); // (Output) YASA MC voltage
Serial mc(p28, p27); // (Input/Output) Motor Controller serial line
PwmOut mc2(p21);    // (Output) PWM line to new Motor Controller

LocalFileSystem local("local");

#if (TEST_BUILD == true && TEST_TX == true)
AnalogIn test_engine_rpm(p16);  // (Input) Fake Engine RPM signal
#endif

CAN vnet(p30, p29); // (Input/Output) Vehicle CAN network lines
CANMessage cmsg; // Stores most recent, highest priority CAN message.


int main() {
    bool SEND = true;
    unsigned long long ice_rpm = 0;
    float waitDelay = 0.01;
    float avg_att = 0.00;
    bool cutYasa=false;
    
    mc2.period_ms(20);
    
    while (1) {
#if (TEST_BUILD == true && TEST_TX == true)
        unsigned long long n = int(test_engine_rpm * 15000);
        char * adr = new char [2];
        char first = (n >> 8) & 0xFF;
        char second = n & 0xFF; 
        adr[0] = second;
        adr[1] = first;

        vnet.write(CANMessage(0x610, adr));
        wait(0.05);
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
            }
        }
                
        if (ice_rpm >= ICE_REV_LIMIT) 
        {
            utils::set_leds(true, true, true, true);
            cutYasa=true;
            //continue;
            
        }
         else 
        {
            cutYasa=false;  
            utils::set_leds(false, false, false, false);
        }
        
        // Set the Yasa MC to match the attenuator
        // TODO: check for huge difference
        avg_att = (att_ch1 + (2.9f-att_ch2)) / 2.00;
        if(cutYasa)
        yasa=0;
        else
        yasa = avg_att;
        int target = int(avg_att * 2000.00 + 300);
        if (target > 2500) {
            target = 2500;
        } else if (target < 0) {
            target = 0;
        }
            
        mc2.pulsewidth_us(target);
        wait(waitDelay);
    }
}
