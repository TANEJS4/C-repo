//Author: Shivam taneja
#include <stdio.h>
#include <stdlib.h>

int main(){
    char file1[100];
    unsigned nLine = 0 ,i =0;
    puts("Input the 1st file name:");
    scanf("%s", file1);
    puts("Input the number of lines to be added");
    scanf("%d", &nLine);

    // file to be Appended
    FILE *fPtr = fopen(file1, "a");

    if (fPtr == NULL || nLine == 0){ //if the file doesnt exist or number of line can not be processed
        puts("File could not be open or enter valid number of lines");
        exit(1);
    }

    else{
        puts("The lines are");
        char context[1000];
        while( i < nLine){ //iterativly appending text ton the file
            scanf("%s", context);

            fprintf(fPtr,"%s\n",context);
            i++;
        }
    }
    fclose(fPtr);
}
