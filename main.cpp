//=====[Libraries]=============================================================


#include "arm_book_lib.h"
#include "pc_serial_com.h"
#include "non_blocking_delay.h"
#include "wifi_com.h"
#include "Servo.h"
#include "Servo_control.h"
#include "Button.h"

#define SYSTEM_TIME_INCREMENT_MS   10
//=====[Main function, the program entry point after power on or reset]========
static nonBlockingDelay_t smartHomeSystemDelay;
extern char parsedExt[32];

int main()
{
    tickInit();
    buttonInit();
    pcSerialComInit();
    wifiComInit();
    servoControlInit();
    nonBlockingDelayInit( &smartHomeSystemDelay, SYSTEM_TIME_INCREMENT_MS );
    while (true) {
        if( nonBlockingDelayRead(&smartHomeSystemDelay) ) {
        wifiUartReading();
        pcSerialComUpdate();
        servoControlUpdate();
    }    
    wifiComUpdate();
    }
}