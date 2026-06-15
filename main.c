// hello world

#include <stdio.h>

int main() {
int age;
  
  printf("enter age:");
  scanf("%d",&age);
  printf("you said %d",age);

  if (age >= 18){
    printf("you can drink");
  } else{
    for (int i=0; i < 5; i++){
      printf("No No No");
    }
  }
  
return 0;
}
