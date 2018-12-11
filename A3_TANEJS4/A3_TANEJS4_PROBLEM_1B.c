//Author: shivam Taneja
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>



// Recuriosn


 unsigned int fib(unsigned int n); //Prototype function

 int main(){
     // struct rusage r_usage; //Reference http://appcrawler.com/wordpress/2013/05/13/simple-example-of-tracking-memory-using-getrusage/

     // getrusage(RUSAGE_SELF,&r_usage); //gets the memory usage
     // clock_t t;
     //  t = clock();
     // Print the maximum resident set size used (in kilobytes);
     // printf("Memory usage: %ld kilobytes\n",r_usage.ru_maxrss);
   unsigned int num; //creating all positive varible num

   printf("Enter the Nth term: ");
   scanf("%d", &num); //putting value in num

   unsigned int result = fib(num); //storing result of fucntion fib in result
     printf("%d\n", result); //printing value
     // t = clock() - t;
     //  double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
     //  printf("%f seconds to execute \n", time_taken);
     // }

 }

 unsigned int fib(unsigned int x){ // defining function
   if (x == 1 || x == 0){ //base case
     return x;
   }
   else{ //doing recurision
     return (fib(x - 1) + fib(x - 2));

   }

 }
