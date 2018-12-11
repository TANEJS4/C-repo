//Author: tanejs4
//Author: Shivam Taneja


#include<stdio.h>

int power2(int number, int pow);
void displayBits(unsigned int value);

int main(){
    int number;
    unsigned pow;

    puts("enter number:");
    scanf("%d",&number);

    puts("\nenter power to 2:");
    scanf("%d",&pow);

    int result = power2(number, pow);
    printf("Result in decimal\n \n%d",result);

    printf("\nResult in Binary\n \n");

    displayBits(result);
}
int power2(int number, int pow){
    number = number << pow;

    return number;
}

void displayBits(unsigned int value){
    unsigned int displayMask = 1 << 31;
    for(unsigned int c =1; c <= 32; ++c){
        putchar(value & displayMask ? '1': '0');
        value <<= 1;
        if (c % 8 == 0){
            putchar(' ');
        }
    }
    putchar('\n');
}
