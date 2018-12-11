//Author: shivam Taneja
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <math.h>


// recurision

void hanoi(unsigned int num,unsigned int from_peg, unsigned int des_peg ,unsigned int temp_peg);
//Prototype function

void hanoi(unsigned int num,unsigned int from_peg, unsigned int des_peg ,unsigned int temp_peg)
{ //defining function
   if (num == 1) //base case
   {
       printf("\n %d -> %d", from_peg, des_peg);
       return; //if true continue with iteration or end
   }
   hanoi(num - 1, from_peg, temp_peg, des_peg); // new values for next iteration because this time we switch temp_peg and des_peg
   printf("\n %d -> %d", from_peg, des_peg); //print
   hanoi(num - 1, temp_peg, des_peg, from_peg); //again new values for next iteration because this time we change places for temp_peg, des_peg and from_peg
}
int main(){
   // struct rusage r_usage; //Reference http://appcrawler.com/wordpress/2013/05/13/simple-example-of-tracking-memory-using-getrusage/

   // getrusage(RUSAGE_SELF,&r_usage);
   // Print the maximum resident set size used (in kilobytes).
   // printf("Memory usage: %ld kilobytes\n",r_usage.ru_maxrss);
 // clock_t t;
//  t = clock();
 unsigned int nDisk, from_peg, des_peg, temp_peg; //CREATing variables

 printf("Number of disks: " ); //prompt for input variable
 scanf("%d",&nDisk); //putting value to variable
 printf("Initial peg: " ); //prompt for input variable
 scanf("%d",&from_peg);//putting value to variable
 printf("destination peg: " ); //prompt for input variable
 scanf("%d",&des_peg);//putting value to variable
 printf("temporary peg: " ); //prompt for input variable
 scanf("%d",&temp_peg);//putting value to variable


 hanoi(nDisk,from_peg, des_peg, temp_peg); //calling function for recursion and result
//  t = clock() - t;
//  double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
//  printf("%f seconds to execute \n", time_taken);
////2.254974  for 20 disks
}
