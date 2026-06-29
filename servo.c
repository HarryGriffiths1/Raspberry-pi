// control servo :)

#include <stdio.h>
#include <wiringPi.h>

#define SERVO 13 // tick from 50 to 260

int angleToTick(int angle){
    // 0 = 50
    // 180 = 260
    //210/180 = 1.1666666
    double multiplyer = 210/180;
    if(angle == 0){
        return 50;
    }
    else if(angle = 180){
        return 260;
    }
    else{
        return (int)(50+(angle*multiplyer));
    }
}

int main(){

    wiringPiSetupGpio();
    pinMode(SERVO, PWM_MS_OUTPUT);
    pwmSetRange(2000); // 1 tick is 0.01 ms so 20ms range
    pwmSetClock(192); // need 50hz so 19200/ range(2000) / clock(192) = 0.05khz

    int pulse;
    printf("go to:");
    scanf("%d",&pulse);

    pwmWrite(SERVO, pulse); // set to place of "pulse"

    return 0;
}