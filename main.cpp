#include "../mbed/mbed.h"



DigitalOut myled(LED1);
DigitalOut led2(LED2);
//PwmOut motor(p21);
Serial device(p9, p10);
AnalogIn   ain(p19);
AnalogOut  aout(p18);

using namespace std;
//DigitalOut myled(LED1);
//PwmOut motor(p21);

    float APP1_voltage=0.5;
    float APP2_voltage=0.5;
    int APP_cent=0; 

    float MC1=0;
    float MC2=0;
    
    char mode=0; //Endurance(E=69)  Race(R=82) //using char to save memory 
    int soc=0;// can be float too
    int ICErpm=0;
    int WHEELrpm=0;


    int convert_volt_to_cent( float app,float baseVoltage)
     {
     return((int)(app/baseVoltage*100));
     }

    int convert_cent_to_volt(int centValue,float baseVoltage )
    {
    return(float(baseVoltage*centValue/100));
    }
    float getAPP()
    {
        //find APP by mean and convert to percent- store in APP_cent
        APP2_voltage=ain*3.3f;
        APP1_voltage=APP1_voltage;
        APP_cent=convert_volt_to_cent((APP1_voltage+APP2_voltage)/2,3.3f);
        return APP_cent;
    }
     
     
     void setAPP(float app1,float app2)
     {
         APP1_voltage=app1;
         APP2_voltage=app2;
     }
     
     void getICE_rpm()
     {
         //get rpm from CAN
     }

     bool checkEngineRPM(int revLimit=13600)
     {
         if(ICErpm<revLimit)
             return true;
         else 
             return false;
     }
     
     void setMC1()
     {
        MC1= convert_cent_to_volt(APP_cent, 1.0f);  
     }
     void setMC2()
     {
        MC2= convert_cent_to_volt(APP_cent, 5.0f);  
     }
    
   
     // check for error- code to be implemented

int main() 
{

    int RevLimit=13000;
   // MC [2][100][100][20]; //MC[mode][soc][APP][GNDrpm= 2000/100]
    //MC look_up_table [2][10][5][100][14];// MC[mode][soc][gear][app][ENGINErpm=14000/1000]
   
    //voidFunc();
   // p.write(1);
    device.baud(9600);
    device.putc(131);
    device.putc(0x85);
    device.putc(0x00);
              
    while(1) 
    {
        //cycle starts here
        
         //demo code
        myled = 1;
       // wait(0.2);
        myled = 0; 
        //wait(0.2);
          getAPP();
          //getICE_rpm();
          //check if engine rpm <rev limit
          if(checkEngineRPM(RevLimit))
          {
              //setMC1();
              //motor.period(0.10f);
              //motor.write(MC1);
              device.putc(0x85);
              device.putc(0x00);
              device.putc(APP_cent/4);
              led2 = 1;
              //wait(convert_cent_to_volt(APP_cent,1.0f));
              //for(int i=0;i<ain;i=i+0.1f)
              wait(ain);
              led2 = 0; 
              //wait(convert_cent_to_volt(APP_cent,1.0f));
              wait(ain);
              //aout=ain*2.0f;
              aout=ain;
          }
         
          
        
    }
}
