//Author: TANEJS4

//I learned pointers online on youtube way before we learned in class.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b) ;              //prototpe function that uses two pointers as input

int main(){
  int n;
  printf("Define size of array: ");      //prompt for size of array
  scanf("%d",&n);
  int array[n];                         //setting and creating array of size n
  for(int i=0; i<n; i++){
    int k = i+1;                         //for the ease of user to understand the index
    printf("element %d: ",k);
    scanf("%d", &array[i]);             //storing value in array at index `i`
  }
  srand(time(NULL));                     //to create random number

  for (int i  = n-1;i>0;i--){
    int j = rand() % (i +1);              //j is a random number that does arithmatic expression  % (i +1)
                                    // and store the resulting value in j
    swap(&array[i],&array[j]);      //calling function swap
  }

  for(int i =0; i<n;i++){           //to print every index in  `array`
    printf("\t %d \n",array[i]);
    }



}
  void swap(int *a, int *b) {               //defining function
      int temp = *a;                         //temporary  integer equal to pointer value of a
      *a = *b;                              //changing values of a with b pointer
      *b = temp;                             //finally changing values of b with temp which here is equal to pointer a
  }
