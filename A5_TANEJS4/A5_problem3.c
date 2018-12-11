//Author: shivam Taneja
#include <stdio.h>
#include <string.h>

int main()
{
  // These should be initialized before use.
  char pig[100] = "";
  char p[10] = "";

  printf("What word would you like to change into Pig Latin: ");
  scanf("%s", pig);

  unsigned long length = strlen(pig); // strlen returns an unsigned long
  strncat(p, pig, 1); // This needs a pointer to char

  for(int j = 0; j < length; j++)
  {
    pig[j] = pig[j + 1];
  }

  strcat(pig, p);
  strcat(pig, "ay");
  printf("%s\n", pig);
  return 0;
}
