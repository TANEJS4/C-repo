#include <stdio.h>

int main(){
  unsigned int index;                   //getting number of rows
printf("The matrix will be a square matrix so NxN");
  printf("number of elements in each row:"); //prompt
  scanf("%d",&index);                    //storing value in `index`
  int matrix[index][index];

  /*making multidimensional array where first [] is for the index and
  second [] is for all the numbers to be added in each row  */


  for (int i =0;i <index; i++){             //loop for scanning values at each first [] index
    printf("input elements for %d\n",i);    //promt
    for (int j =0;j <index;j++){            // storing elements of each row
      printf("Element %d: ",j);
      scanf("%d", &matrix[i][j]);            //storing values in `j` of matrix[i][j]
    }
  }
  int sum =0;                                   //decalaring varibale
  for(int i =0 ; i <index; i++){                //loop for scanning through each first [] index
    for (int j=0;j<index;j++ ){                 //loop for every element in each first [] index
      if(i < j){                                //explained below
        sum += matrix[i][j];                    //adding the value to sum
      }
    }
  }

  printf("\n");
  printf("%d",sum);                             //printing sum of upper triangular
}
/*

eg 3*3 matric -->  [index,element position]
[ 1    2   3 ]  --> [0,0    0,1   0,2]
[ 4    5   6 ]  --> [1,0    1,1   1,2]
[ 7    8   9 ]  --> [2,0    2,1   2,2]

loop checks if element position is greater than index,
hence all the upper triangular element

loop checka this condition for every index and if
condition is true, adds it up to `sum`

*/
