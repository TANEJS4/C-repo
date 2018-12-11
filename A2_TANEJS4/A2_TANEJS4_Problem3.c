//Author: TANEJS4

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int gcd(int x, int y);  //Prototype gcd function
int gcd(int x, int y){ //defining gcd function
  int i, g; //two variable i = number to be divided and g = result
  for(i=1; i <= x && i <= y; ++i) //using for loop for every number
    {
        // Checks if i is factor of both integers
        if(x%i==0 && y%i==0)
            g = i;

    }
    return g; //returning solution
}

int main(){
  int x, y; //variables for two input number
  printf("Enter first number: ");
  scanf("%d", &x); //first input
  printf("Enter second number: ");
  scanf("%d", &y);//second input
  int sol = gcd(x,y); 
  printf("%d", sol);
  return sol; //returning solution
}
