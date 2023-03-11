#include "mbed.h"
#include "arm_book_lib.h"
#include "Servo.h"
#include "Button.h"
#include "non_blocking_delay.h"

InterruptIn LEFTButton(D0);
InterruptIn UPButton(D2);
InterruptIn RIGHTButton(D5);
InterruptIn DOWNButton(D7);

static void inturptLeft();
static void inturptRight();
static void inturptUp();
static void inturptDown();
static nonBlockingDelay_t servoMoveDelay;
bool Left = false;
bool Right = false;
bool Up = false;
bool Down = false;


void buttonInit(){
   LEFTButton.mode(PullDown);
   UPButton.mode(PullDown);
   RIGHTButton.mode(PullDown);
   DOWNButton.mode(PullDown);
   LEFTButton.rise(&inturptLeft);
   UPButton.rise(&inturptUp);
   RIGHTButton.rise(&inturptRight);
   DOWNButton.rise(&inturptDown);
   nonBlockingDelayInit( &servoMoveDelay, SERVO_TIME_INCREMENT_MS );
}


bool leftButton(){
   if (LEFTButton){
       Left = true;
   }
   if (!LEFTButton){
       Left = false;
   }
   return Left;
}


bool rightButton(){
   if (RIGHTButton){
       Right = true;
   }
   if (!RIGHTButton){
       Right = false;
   }
   return Right;
}


bool upButton(){
   if (UPButton){
       Up = true;
   }
   if (!UPButton){
       Up = false;
   }
   return Up;
}


bool downButton(){
   if (DOWNButton){
       Down = true;
   }
   if (!DOWNButton){
       Down = false;
   }
   return Down;
}

static void inturptLeft(){
    for(int i = 0;i<20;i++){
       
            leftMovement();
    }
}
static void inturptRight(){
    for(int i = 0;i<20;i++){
       
            rightMovement();
    }
}
static void inturptUp(){
    for(int i = 0;i<10;i++){
       
            upMovement();
    }
}
static void inturptDown(){
    for(int i = 0;i<10;i++){
       
            downMovement();
        }

}

