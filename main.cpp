#include "../mbed/mbed.h"
#include "ThrottleBodyCtrl.h"
#include "utils.h"


//Serial controller(p28, p27);

AnalogIn att(p19);
AnalogIn tps(p20);
AnalogOut pimu(p18);


float APP1_voltage = 0.5;
float APP2_voltage = 0.5;
int APP_cent = 0;

float MC1 = 0;
float MC2 = 0;

char mode = 0; //Endurance(E=69)  Race(R=82) //using char to save memory 
int soc = 0; // can be float too
int ICErpm = 0;
int WHEELrpm = 0;

int convert_volt_to_cent(float app, float baseVoltage) {
    return ((int) (app / baseVoltage * 100));
}

int convert_cent_to_volt(int centValue, float baseVoltage) {
    return (float(baseVoltage * centValue / 100));
}

float getAPP() {
    //find APP by mean and convert to percent- store in APP_cent
    APP2_voltage = att * 3.3f;
    APP1_voltage = APP2_voltage;
    APP_cent = convert_volt_to_cent((APP1_voltage + APP2_voltage) / 2, 3.3f);
    return APP_cent;
}

void setAPP(float app1, float app2) {
    APP1_voltage = app1;
    APP2_voltage = app2;
}

void getICE_rpm() {
    //get rpm from CAN
}

bool checkEngineRPM(int revLimit = 13600) {
    if (ICErpm < revLimit)
        return true;
    else
        return false;
}

void setMC1() {
    MC1 = convert_cent_to_volt(APP_cent, 1.0f);
}

void setMC2() {
    MC2 = convert_cent_to_volt(APP_cent, 5.0f);
}

    Serial mc(p28, p27);

void idle(ThrottleBodyCtrl ctrl) {
    float skewed_tps = tps - 0.1030f;
    if (skewed_tps < 0.50f) {
        mc.putc(0x85);
        mc.putc(0x85);
        mc.putc(0x30);
        //ctrl.increase();
    } else {
        mc.putc(0x85);
        mc.putc(0x85);
        mc.putc(0x10);
    }
    return;
}

int main() {
    ThrottleBodyCtrl tbCtrl(&mc, &tps);
    int RevLimit = 13000;

    utils::led_num(0);

    while (1) {
        float skewed_tps = tps - 0.1030f;

        getAPP();

        if (att < 0.50f) {
            tbCtrl.idle();
        } else {
            if (checkEngineRPM(RevLimit)) {
                if ((att - 0.05f) < skewed_tps && skewed_tps < (att + 0.05f)) {
                    tbCtrl.hold();
                } else if (att < skewed_tps && skewed_tps > 0.50f) {
                    tbCtrl.decrease();
                }
                else if (att > skewed_tps) {
                    tbCtrl.increase();
                }
            }
        }
    }
}
