#include "../mbed/mbed.h"
#include "ThrottleBodyCtrl.h"
#include "utils.h"

const int ICE_REV_LIMIT = 13000;

AnalogIn att(p19);  // (Input) Attenuator signal
AnalogOut yasa(p18); // (Output) YASA MC voltage
Serial mc(p28, p27); // (Input/Output) Motor Controller serial line
PwmOut mc2(p21);    // (Output) PWM line to new Motor Controller

CAN vnet(p9, p10); // (Input/Output) Vehicle CAN network lines
CANMessage cmsg; // Stores most recent, highest priority CAN message.


int main() {
    char counter = 42;
    int ice_rev = 0;
    float waitDelay = 0.01;
    
    mc2.period_ms(20);
    
    while (1) {
        if (vnet.read(cmsg)) {
            if (cmsg.id == 1337) {
                if (cmsg.data[0] == 42) {
                    utils::set_leds(true, true, true, true);
                }
            }
        }
        
        if (ice_rev >= ICE_REV_LIMIT) {
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
