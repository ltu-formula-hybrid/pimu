#include "../mbed/mbed.h"
#include "ThrottleBodyCtrl.h"
#include "utils.h"


#define TEST_BUILD false
#define TEST_TX false

const int ICE_REV_LIMIT = 13000;

AnalogIn att(p19);  // (Input) Attenuator signal
AnalogOut yasa(p18); // (Output) YASA MC voltage
Serial mc(p28, p27); // (Input/Output) Motor Controller serial line
PwmOut mc2(p21);    // (Output) PWM line to new Motor Controller
#if (TEST_BUILD == true && TEST_TX == true)
AnalogIn test_engine_rpm(p16);  // (Input) Fake Engine RPM signal
#endif

CAN vnet(p30, p29); // (Input/Output) Vehicle CAN network lines
CANMessage cmsg; // Stores most recent, highest priority CAN message.


int main() {
    bool SEND = true;
    unsigned long long ice_rpm = 0;
    float waitDelay = 0.01;
    
    mc2.period_ms(20);
    
    while (1) {
#if (TEST_BUILD == true && TEST_TX == true)
        const char engine_rpm = int(test_engine_rpm * 15000);
        vnet.write(CANMessage(0x610, &engine_rpm, 1));

        wait(0.5);
        utils::set_leds(false, false, false, false);
        wait(0.5);
        utils::set_leds(true, true, true, true);
        continue;
#endif
        
        if (vnet.read(cmsg)) {
            if (cmsg.id == 0x610) {
#if (TEST_BUILD == true && TEST_TX == false)
                utils::set_leds(false, false, false, false);
                wait(0.5);
                utils::set_leds(true, true, true, true);
                wait(0.5);
#endif
                char first_byte = cmsg.data[0];
                char second_byte = cmsg.data[1];
                
                // Rotate the bytes for Big Endianness
                first_byte = (first_byte >> 1) | (first_byte << 7);
                second_byte = (second_byte >> 1) | (second_byte << 7);
                ice_rpm = second_byte + first_byte;
            }
        }
        
        if (ice_rpm >= ICE_REV_LIMIT) {
            yasa = 0;
            continue;
        }
        
        // Set the Yasa MC to match the attenuator
        yasa = att;
        int target = int(att * 2000.00 + 300);
        if (target > 2500) {
            target = 2500;
        } else if (target < 0) {
            target = 0;
        }
            
        mc2.pulsewidth_us(target);
        wait(waitDelay);
    }
}
