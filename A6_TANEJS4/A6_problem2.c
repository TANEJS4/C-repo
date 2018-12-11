//Author: tanejs4
//Author: Shivam Taneja

#include <stdio.h>

unsigned int packCharacter(unsigned char ch1, char ch2);
void displayBits(unsigned int value);

int main(){
  unsigned char ch1,ch2;
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
unsigned int packCharacter(unsigned char ch1, char ch2){
    printf("\nThe characters in binary is -  after\n");
    // displayBits(ch1);

    displayBits((ch1 << 8) | ch2 );

}

void displayBits(unsigned int value){
    unsigned int displayMask = 1 << 15;
    for(unsigned int c =1; c <= 16; ++c){
        putchar(value & displayMask ? '1': '0');
        value <<= 1;
        if (c % 8 == 0){
            putchar(' ');
        }
    }
}
