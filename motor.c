#include <stdio.h>
#include <wiringPi.h>

#define STEP 17
#define DIR 27
#define EN 22
#define BUTTON 27

void main() {
wiringPiSetupGpio();

    pinMode(STEP, OUTPUT);
    pinMode(DIR, OUTPUT);
    pinMode(EN, OUTPUT);
    pinMode(BUTTON, INPUT);
    pullUpDnControl(BUTTON, PUD_UP);

    digitalWrite(EN, LOW);   // enable
    digitalWrite(DIR, HIGH); // set direction

    bool pressed = 0;

    while(pressed){

        digitalWrite(STEP, HIGH);
        delayMicroseconds(50000);

        digitalWrite(STEP, LOW);
        delayMicroseconds(50000);
        
        pressed = !(digitalRead(BUTTON) == LOW);
    }
}