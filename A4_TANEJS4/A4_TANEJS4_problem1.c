//Author: TANEJS4

#include <stdio.h>



int main(){
  int i,j,k, counter =0 ;
  int howMany;

  printf("\nPrint all unique elements of an array\n");
  printf("Input the number of elements to be stored in the array :"); //prompt

  scanf("%d",&howMany);              //storing value in howMany

  int element[howMany];             //making array `element` of size `howMany`


  printf("only integer value accepted");    //prompt for kind of input accepted
  for(i=0; i<howMany; i++){                 //for making an array
    int num = i;
    printf("element %d: ",num+1);           //prompt for postition in array
    scanf("%d", &element[i]);               //storing value in  `element`
  }

  printf("\n \n");

  for(i=0; i<howMany; i++){             //loop that checks every postition in `element`
        counter=0;
        for(j=0; j<i-1; j++){               // Check  before current position and
            if(element[i]==element[j]){     //condition if duplicate found
                counter++;                   //increase counter by 1
            }
        }
        
       for(k=i+1; k<howMany; k++){               // Check  after current position and
            if(element[i]==element[k]) {        //condition if duplicate found

                counter++;                      //increase counter by 1
            }
        }

       if(counter==0){                          //checks value for counter ie if found at position `i` it wont print else it will
          printf("%d \n",element[i]);
        }
    }
}
