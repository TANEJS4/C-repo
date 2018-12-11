//Author: shivam Taneja
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>


//Fibonacchi series
// Iterative

int main(){
// struct rusage r_usage; //Reference http://appcrawler.com/wordpress/2013/05/13/simple-example-of-tracking-memory-using-getrusage/

   // getrusage(RUSAGE_SELF,&r_usage);
   // Print the maximum resident set size used (in kilobytes).
   // printf("Memory usage: %ld kilobytes\n",r_usage.ru_maxrss);
 // clock_t t;
 // t = clock();
    unsigned int j, n, a = 0, b = 1, nValue; //creating base VARIABLES

    printf("Enter the Nth terms: ");
    scanf("%d", &n); //Taking input number


    for (j = 1; j <= n; ++j) //using for loop to get value
    {

        nValue = a + b; // nValue adds a and b (refernce to base case in recurision)
        a = b; //replacing value of a with b for next iteration
        b = nValue; //replacing value of b with nValue for next iteration
    }printf("%d \n ", a);
    // t = clock() - t;
    // double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    // printf("%f seconds to execute \n", time_taken);
}
