#include "../mbed/mbed.h"
#include "ThrottleBodyCtrl.h"
#include "utils.h"


#define TEST_BUILD true
#define TEST_TX false

const int ICE_REV_LIMIT = 5000;

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
    unsigned long long ice_rpm = 0;
    float waitDelay = 0.01;
    float avg_att = 0.00;
    float last_att = -1.00;
    time_t last = 0;
    time_t now = time(NULL);
    
    mc2.period_ms(20);
    int test_rpm = 0;
    
    while (1) {
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
                

        if (ice_rpm >= ICE_REV_LIMIT) {
#if (TEST_BUILD == true && TEST_TX == false)
            utils::set_leds(true, true, true, true);
#endif
            yasa = 0;
            continue;
        } else {
#if (TEST_BUILD == true && TEST_TX == false)
            utils::set_leds(false, false, false, false);
#endif
        }
        
        // Set the Yasa MC to match the attenuator
        // TODO: check for huge difference
        avg_att = (att_ch1 + att_ch2) / 2.00;
        
        last_att = avg_att;

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
