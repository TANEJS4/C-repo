//Author: TANEJS4

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int multiple(int x, int y); //Prototype function
int multiple(int x, int y){ //defining function
  int mul = y % x; //checking if x is multiple of y
  if (mul == 0){
    return 1;
  }
  else{
    return 0;
  }
}
int main(){
  int x, y;
  printf("Enter first number: ");
  scanf("%d", &x); //input of first side
  printf("Enter second number: ");
  scanf("%d", &y);//input of second side
  int sol = multiple(x,y)
  if (sol == 1){
    printf("It is the multiple\n");

  }
  else{
    printf(" It is not a multiple\n", );
  }
  printf("%d", sol);
  return sol;
}
