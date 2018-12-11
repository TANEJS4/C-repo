//Author: Shivam taneja
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char file1[100],file2[100],file3[100]; //strings with 100 characters
   puts("Input the 1st file name:");
   scanf("%s", file1); //getting file1 path
   puts("Input the 2st file name:");
   scanf("%s", file2); //getting file2 path
   puts("Input the new file name where to merge the above two files :");
   scanf("%s", file3); //getting file3 path
   // Open two files to be merged

   FILE *fPtr1 = fopen(file1, "r");
   FILE *fPtr2 = fopen(file2, "r");
   // Open file to store the result
   FILE *fPtr3 = fopen(file3, "w");
   char c;

   //if any of the file doesnt exist
   if (fPtr1 == NULL || fPtr2 == NULL || fPtr3 == NULL)
   {
         puts("Could not open files");
         exit(1);
   }

   // Copy contents of first file to file3.txt
   while ((c = fgetc(fPtr1)) != EOF)
      fputc(c, fPtr3);

   // Copy contents of second file to file3.txt
   while ((c = fgetc(fPtr2)) != EOF)
      fputc(c, fPtr3);

   printf("The two files merged into mergefiles.txt file successfully...!\n");

   fclose(fPtr1);
   fclose(fPtr2);
   fclose(fPtr3);
}
