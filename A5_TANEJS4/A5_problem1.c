//Author: Shivam Taneja
#include <stdio.h>
#include <math.h>

void circum(double radius);
void area(double radius);
void volume(double radius);
void menu();
const float  PI = 3.141593;
int main()//mf
{
     void(*f[3])(double)={circum, area, volume};//ary of 3 pnters return void
     double choice;
     while(choice >=0 && choice < 3)//loop
     {
           menu();
           scanf("%d", &choice);

        if(choice != 3)
        {
            (*f[choice])(choice);
        }
        else
        {
            printf("Exit program.");
        }
     }

    return 0;
}

void menu( void )
{
    printf( "Select an option:\n\n"
    "0 Calculate the circumference of a Circle\n"
    "1 Calculate the area of a Circle\n"
    "2 Calculate the volume of a Sphere\n"
    "3 exit\n");
}

void circum(double radius)
{
    printf("\n\nEnter the radius of the circle: ");
    scanf("%lf", &radius);
    printf("\nRadius= %.3f", radius);
    double circmfrnce = 2.0 * PI * radius;
    printf("%s%.2f%s\n\n", "\nThe circumference of the circle is ", circmfrnce, " meters.");
}

void area(double radius)
{
    puts("\n\nEnter the radius of the circle: ");
    scanf("%lf",&radius);
    printf("\nRadius= %.3f", radius);
    double area = PI * pow(radius, 2);
    printf("\n%s%.2f%s\n\n","The area of the circle is ", area, " meters squared.");
}//end area function

void volume(double radius)
{
    puts("\n\nEnter the radius of the sphere: ");
    scanf("%lf",&radius);
    printf("\nRadius= %.3f", radius);
    double volume = (4.0/3.0) * PI * pow(radius ,3);
    printf("%s%.2f%s\n\n", "\nThe volume of the sphere is ", volume,  " cubic meters.");
}
