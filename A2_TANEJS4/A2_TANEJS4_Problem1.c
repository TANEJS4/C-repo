//Author: TANEJS4

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double hypotenuse(double x1, double y1); //Prototype function of hypotenuse
int main(){
  double x , y; //Defining two sides of type double
  scanf("%lf\n", &x); //input of first side
  scanf("%lf", &y); //input of second side
  double sol = hypotenuse(x,y); // using variable sol as the solution of the function
  printf("Hypotenuse: %.3lf", sol);
  return sol;
}
double hypotenuse(double x1, double y1){ //Defining function

  return sqrt((x1*x1) + (y1*y1)); //formula for hypotenuse
}
