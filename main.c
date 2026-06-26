// hello world

#include <stdio.h>
#include <wiringPi.h>

# define BUTTON 27


void age_check(int r_age) {
int age;
  
  printf("enter age:");
  scanf("%d",&age);
  printf("you said %d",age);

  if (age >= r_age){
    printf("you can drink");
  } else{
    for (int i=0; i < 5; i++){
      printf("No No No\n");
    }
  }
  
}

int main(){
  wiringPiSetupGpio();

  if (wiringPiSetup() == -1) {
    printf("Failed to initialize wiringPi\n");
    return 1;
  }

  pinMode(BUTTON, INPUT);
  pullUpDnControl(BUTTON, PUD_UP);

  while (1){
        printf("%d\n", digitalRead(BUTTON));
        delay(200);

        if (digitalRead(BUTTON) == LOW){
            // age_check(18);
        }
        delay(50); // debounce
    }

  return 0;
}