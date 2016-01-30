#include "../mbed/mbed.h"
#include "ThrottleBodyCtrl.h"
#include "utils.h"

const int ICE_REV_LIMIT = 13000;

AnalogIn att(p19);  // (Input) Attenuator signal
AnalogIn tps(p20);  // (Input) Throttle Position Sensor signal
AnalogOut yasa(p18); // (Output) YASA MC voltage
Serial mc(p28, p27); // (Input/Output) Motor Controller serial line

CAN vnet(p9, p10); // (Input/Output) Vehicle CAN network lines
CANMessage cmsg; // Stores most recent, highest priority CAN message.


int main() {
    int ice_rev = 0;
    
    ThrottleBodyCtrl tbCtrl(&mc, &tps);
    tbCtrl.idle();
    
    float waitDelay = 0.00001;

    while (1) {
        if (vnet.read(cmsg)) {
            if (cmsg.id == 1) { // Change to appropraite CAN message ID
                // convert CAN message to int RPM value
                // ice_rev = can message contents
            }
        }
        
        if (ice_rev >= ICE_REV_LIMIT) {
            //tbCtrl.idle();
            yasa = 0;
            continue;
        }
        
        // Set the Yasa MC to match the attenuator
        yasa = att;
        
        
        float tps = tbCtrl.percent();

        if ((att - 0.07f) < tps && tps < (att + 0.07f)) { // hold
            tbCtrl.increaseAmt = tbCtrl.defaultIncreaseAmount;
            tbCtrl.decreaseAmt = tbCtrl.defaultDecreaseAmount;
            
            if (tps > 0.80f) {
                mc.putc(0x85); // Set motor to forward diretion
                mc.putc(0x00);
                mc.putc(0x25);
            } else {
                mc.putc(0x85); // Set motor to forward diretion
                mc.putc(0x00);
                mc.putc(0x10); 
            }
            
            wait(waitDelay); 
        } else if (att < tps) { // decrease
            tbCtrl.decrease();
            
            tbCtrl.decreaseAmt -= 0x01;
            if (tbCtrl.decreaseAmt < 0x00) {
                 tbCtrl.decreaseAmt = 0x00;
            }
            
            wait(waitDelay);                
        }
        else if (att > tps) { // increase
            tbCtrl.increase();
            
            if (att - tps > 0.50f) {
                tbCtrl.increaseAmt += 0x03;
            } else {
                tbCtrl.increaseAmt += 0x01;
            }
            if (tbCtrl.increaseAmt > 0x25) {
                tbCtrl.increaseAmt = 0x25;
            }
            
            wait(waitDelay);
        }
    }
}
