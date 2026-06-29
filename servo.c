// control servo :)

#include <stdio.h>
#include <wiringPi.h>

#define SERVO 13

int main(){

    wiringPiSetupGpio();
    pinMode(SERVO, PWM_MS_OUTPUT);
    pwmSetRange(2000); // 1 tick is 0.01 ms so 20ms range
    pwmSetClock(192); // need 50hz so 19200/ range(2000) / clock(192) = 0.05khz

    pwmWrite(SERVO, 100); // set 0
    delayMicroseconds(500000);
    pwmWrite(SERVO, 150); // set 90
    delayMicroseconds(500000);
    pwmWrite(SERVO, 200); // set 180
}