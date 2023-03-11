#include "mbed.h"
#include "arm_book_lib.h"
#include "Button.h"
#include "Servo_control.h"
#include "Servo.h"
#include "wifi_com.h"
#include "non_blocking_delay.h"

extern int dutyH;
extern int dutyV;
char upthenDown[] = "up_then_down ";
char sidetoside[] = "side_to_side ";
static nonBlockingDelay_t servoMoveDelay;
static nonBlockingDelay_t siteMoveDelay;

void servoControlInit(){
   motorInit();
   nonBlockingDelayInit( &servoMoveDelay, SERVO_TIME_INCREMENT_MS );
}


void servoControlUpdate(){
    char * parsed = returnParsedExt();

        if (extComparetor(parsed, upthenDown)) {
            for(int i = 0; i<30;i++){
                    upMovement();
            }
            delay(750);//blocking code used because nothing else should run while excuting this command
            for(int y = 0; y<30;y++){
                    downMovement();
        }
   }
           if (extComparetor(parsed, sidetoside)) {
            for(int i = 0; i<50;i++){
                    leftMovement();
            }
            delay(1500);//blocking code used because nothing else should run while excuting this command
            for(int y = 0; y<100;y++){
                    rightMovement();
        }
            delay(1500);//blocking code used because nothing else should run while excuting this command
            for(int y = 0; y<50;y++){
                    leftMovement();
        }
   }
        
   for(int y = 0; y<strlen(parsed);y++){
                parsed[y]=0;
            }

}
