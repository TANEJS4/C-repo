//Author: Shivam Taneja
#include <stdio.h>
#include<stdlib.h>
void add(double x, double y);
void subtract(double x, double y);
void multiply(double x, double y);
void divide(double x, double y);

int main(){

    int choice ;

    void(*f[4])(double,double)={ add, subtract,multiply ,divide };//ary of 3 pnters return void
    printf( "Select an option:\n\n"
        "0 for addition\n"
        "1 for subtraction\n"
        "2 for multiplication\n"
        "3 for division\n"
        "4 exit\n");

    while(choice >=0 && choice < 4){
        scanf("\n%d", &choice);

       if(choice != 4){
           (*f[choice])(choice,choice);
       }
       else{
           printf("\n\nExit program.");
       }
    }
}
void add(double x,double y){

    printf("Enter first number -> x:\n");
    scanf("%lf",&x);
    printf("Enter second number -> y:\n");
    scanf("%lf",&y);

    double result = x + y;
    printf("\nX + Y = %lf", result );
    exit();
}


void subtract(double x,double y){

    printf("Enter first number -> x:\n");
    scanf("%lf",&x);
    printf("Enter second number -> y:\n");
    scanf("%lf",&y);

    double result = x - y;
    printf("\nX - Y = %lf",result );
    exit();

}

void multiply(double x,double y){

    printf("Enter first number -> x:\n");
    scanf("%lf",&x);
    printf("Enter second number -> y:\n");
    scanf("%lf",&y);

    double result = x * y;
    printf("\nX * Y = %lf",result );
    exit();

}

void divide(double x,double y){

    printf("Enter first number -> x:\n");
    scanf("%lf",&x);
    printf("A NON ZERO number should be used for division\n");
    printf("Enter second number -> y:\n");
    scanf("%lf",&y);

    double result = x / y;
    printf("\nX / Y = %lf",result );
    exit();

}
