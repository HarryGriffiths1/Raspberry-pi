#include <stdio.h>
#include <wiringPi.h>

#define STEP 17
#define DIR 27
#define EN 22
#define BUTTON 18

void main() {
wiringPiSetupGpio();

    int dir;
    printf("enter dir: 1 towords 0 away");
    scanf("%d",&dir);

    pinMode(STEP, OUTPUT);
    pinMode(DIR, OUTPUT);
    pinMode(EN, OUTPUT);
    pinMode(BUTTON, INPUT);
    pullUpDnControl(BUTTON, PUD_UP);

    digitalWrite(EN, LOW);   // enable
    digitalWrite(DIR, dir); // set direction

    if( dir == 0){

        int n = 0;

        while( n < 5){
            digitalWrite(STEP, HIGH);
        delayMicroseconds(50000);

        digitalWrite(STEP, LOW);
        delayMicroseconds(50000);
        n += 1;
        }
    }

    printf("%d\n", digitalRead(BUTTON));

    while((digitalRead(BUTTON) == HIGH)){

        digitalWrite(STEP, HIGH);
        delayMicroseconds(50000);

        digitalWrite(STEP, LOW);
        delayMicroseconds(50000);
        printf("%d\n", digitalRead(BUTTON));
    }
}