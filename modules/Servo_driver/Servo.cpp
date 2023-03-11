#include "mbed.h"
#include "arm_book_lib.h"


#define DUTY_MIN 0.03
#define DUTY_MAX 0.112
#define PERIOD 0.02


PwmOut servo(PF_9);
PwmOut servo2(PF_7);


float dutyH = 0.07;
float dutyV = 0.07;






void motorInit(){
servo.period(PERIOD); // 20ms period
servo.write(0.07);
servo2.period(PERIOD); // 20ms period
servo2.write(0.07);
}


void leftMovement(){
   dutyH = dutyH + .001;
   servo2.write(dutyH);
   if (dutyH > 0.112){
       dutyH = 0.112;
   }
}




void rightMovement(){
   dutyH = dutyH - .001;
   servo2.write(dutyH);
   if (dutyH < 0.03){
       dutyH = 0.03;
   }     
}




void upMovement(){
   dutyV = dutyV + 0.001;
   servo.write(dutyV);
   if (dutyV > 0.085){
       dutyV = 0.085;
   }
}




void downMovement(){
   dutyV = dutyV - 0.001;
   servo.write(dutyV);
   if (dutyV < 0.055){
       dutyV = 0.055;
   }
}


