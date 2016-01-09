#include "../mbed/mbed.h"


DigitalOut led_01(LED1);
DigitalOut led_02(LED2);
DigitalOut led_03(LED3);
DigitalOut led_04(LED4);
Serial controller(p28, p27);
AnalogIn ain(p19);
AnalogIn tps(p20);
AnalogOut aout(p18);

using namespace std;
//DigitalOut myled(LED1);
//PwmOut motor(p21);

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
    APP2_voltage = ain * 3.3f;
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


// check for error- code to be implemented

void hold_tps() {
    controller.putc(0x85); // Set motor to forward diretion
    controller.putc(0x00); // nop
    controller.putc(0x10); // Prevent movement
}

void tps_open() {
    controller.putc(0x85); // Set motor to forward diretion
    controller.putc(0x00); // nop
    controller.putc(0x30); // Increase movement
}

int main() {
    
    int RevLimit = 13000;
    // MC [2][100][100][20]; //MC[mode][soc][APP][GNDrpm= 2000/100]
    //MC look_up_table [2][10][5][100][14];// MC[mode][soc][gear][app][ENGINErpm=14000/1000]

    //voidFunc();
    // p.write(1);
    //pololu.baud(9600);
    //pololu.putc(131); // release motor 
    //pololu.putc(0x85); // set motor forward
    //pololu.putc(0x00); // set motor speed to 0 rpm

    while (1) {
        //cycle starts here

        //demo code
        //pimuLED = 1;
        //wait(0.2);
        //pimuLED = 0; 
        //wait(0.2);
        getAPP(); // gets the current APP value 
        //getICE_rpm();
        //check if engine rpm <rev limit
        if (checkEngineRPM(RevLimit)) {
            //setMC1();
            //motor.period(0.10f);
            //motor.write(MC1);

            //              pololu.putc(0x85); // sets motor forward
            //              pololu.putc(0x00); // set speed to 0
            //              pololu.putc(APP_cent/2); // set speed to APP pedal value


            // If app_percent / 50 > current_tps_percent && app_percent <= current_tps_percent
            //if(APP_cent*.5f>convert_volt_to_cent(tps,3.9f)&&APP_cent<=convert_volt_to_cent(tps,3.9f))

            led_01 = 0;
            led_02 = 0;
            led_03 = 0;
            led_04 = 0;
            //wait(.2f);
            //              loopLED = 1;

            float skewed_tps = tps - 0.1030f;
            //aout = float(convert_cent_to_volt(tps * 100, 3.9f)) / 100.0f;
            //              if (skewed_tps < 0.10f) {    
            //                  led_04 = 1;
            //              }
            //              if (ain < 0.10f) {
            //                  led_02 = 1;
            //              }


            //              if ((ain - 0.10f) < skewed_tps && skewed_tps < (ain + 0.10f)) {
            //                  led_01 = 1;
            //              }

            if ((ain - 0.10f) < skewed_tps && skewed_tps < (ain + 0.10f)) {
                hold_tps();
                led_01 = 1;
            }                // else if app_percent < current_tps_percent
            else if (ain < skewed_tps) {
                controller.putc(0x85); // sets motor forward
                controller.putc(0x00); // set speed to 0
                controller.putc(0x05);
                led_03 = 1;
                aout = ain;
            }                // else if app_percent > current_tps_percent
                //else  if(APP_cent>convert_volt_to_cent(tps,3.9f))
            else if (ain > skewed_tps) {
                controller.putc(0x85); // sets motor forward
                controller.putc(0x00); // set speed to 0
                controller.putc(0x30);
                led_02 = 1;
            }
            //wait(0.2f);


            //appLED = 1;
            //wait(convert_cent_to_volt(APP_cent,1.0f));
            //for(int i=0;i<ain;i=i+0.1f)
            //wait(ain);
            //appLED = 0; 
            //wait(convert_cent_to_volt(APP_cent,1.0f));
            //wait(ain);
            //aout=ain*2.0f;
            //aout=ain;
            //tpsLED=1;
            //wait(tps);
            //tpsLED=0;

        }



    }
}
