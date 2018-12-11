//Author: tanejs4
//Author: Shivam Taneja

#include <stdio.h>

void unpackCharacter(unsigned value );

void packCharacter(char ch1, char ch2);
void displayBits(unsigned value);

int main(){
  char ch1,ch2;
  printf("Enter the characters with a space between:");
  scanf("\n%c %c",&ch1,&ch2);

  printf("The characters are %c and %c",ch1,ch2);

  printf("The characters in binary is -  before \n");
  displayBits(ch1);

  putchar('\n');
  displayBits(ch2);

  putchar('\n');
  packCharacter(ch1, ch2);
}

void displayBits(unsigned value){
    unsigned int displayMask = 1 << 31;
    for(unsigned int c =1; c <= 32; ++c){
        putchar(value & displayMask ? '1': '0');
        value <<= 1;
        if (c % 8 == 0){
            putchar(' ');
        }
    }
}

void packCharacter(char ch1, char ch2){
    unsigned pack;
    pack = ch1;
    pack <<= 8;
    pack |= ch2;

    printf("\nThe characters in binary is -\n");

    displayBits(pack);
    putchar('\n');
    unpackCharacter(pack);
}



void unpackCharacter(unsigned value ){
   int ch1, ch2;

   ch1 = value & 65280;

   ch1 >>= 8;
   printf("\nThe character 2 in binary is -\n");
   displayBits(ch1);
   printf( "\nCharacter 2 unpacked: %c\n", ch1 );



   ch2 = value & 255;

   printf("\nThe character 1 in binary is -\n");
   displayBits(ch2);
   printf( "\nCharacter 1 unpacked: %c\n\n", ch2 );

}
