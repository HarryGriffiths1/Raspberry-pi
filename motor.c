#include <stdio.h>
#include <wiringPi.h>

#define STEP 17
#define DIR 27
#define EN 22

void main() {
wiringPiSetupGpio();

    pinMode(STEP, OUTPUT);
    pinMode(DIR, OUTPUT);
    pinMode(EN, OUTPUT);

    digitalWrite(EN, LOW);   // enable
    digitalWrite(DIR, HIGH); // set direction

    while (1){

        digitalWrite(STEP, HIGH);
        delayMicroseconds(50);

        digitalWrite(STEP, LOW);
        delayMicroseconds(500);
    }
}