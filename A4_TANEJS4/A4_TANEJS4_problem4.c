//Author: TANEJS4


#include <stdio.h>
#include <stdlib.h>


int MAX(int array1[]);         //prototpe functions
int howMany;                   //decalaring global variable
int i=0;                      //decalaring global variable
int greater = 0;              //decalaring global variable

int main(){
  printf("Define size of array: ");    //promt for size of array input
  scanf("%d",&howMany);               //storing value in `howMany`
  int array[howMany];                 //making protoype array of size `howMany`

  printf(" All integer should be postive \n" );             //prompt for accepted input

  for(int i=0; i<howMany; i++){       //loop for storing values at each index in  `array`
    int k = i+1;                      //for the ease of user to understand the index
    printf("element %d: ",k);
    scanf("%d", &array[i]);           //storing value in array at index `i`
  }
  int result = MAX(array);            //using function for recursion

  printf("Greatest howManyber is: \n%d\n", result); //printing result
}

int MAX(int array1[]){                  //defining function
  if (i < howMany){                     //checking first condition for a recursion
    if (greater <array1[i]){            //checking new `greater` value and storing in `greater`
      greater = array1[i];
    }
    i++;                                  //increment of i
    MAX(array1);                    //calling function again for recursion to occur
  }
  return greater;                      //finally returing the last stored greatest number
}
