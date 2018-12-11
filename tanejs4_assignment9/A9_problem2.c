//Author: Shivam taneja

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
//self-referenced structure
struct stackNode {
   char data;
   struct stackNode *nextPtr;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

//prototypes functions
void push(StackNodePtr *topPtr, char info);
int check(StackNodePtr *topPtr, char string[100] );
void printStack(char string[100], int result);
bool pop(StackNodePtr *topPtr, char *c);


int main(){
   StackNodePtr stackPtr = NULL;
   char string[100];
   printf("%s","Enter a line of text:\n");

    gets(string);
    for(int i = 0;string[i];i++){ //going through the string input
        if (string[i] != " "){ //ignore spaces
            push(&stackPtr, string[i]); //push it to top of the stack
        }
    }

    int result = check(&stackPtr, string); //getting result from comparing
    puts("\n"); //next line for cleaner outut
    printStack(string, result);
}

void push(StackNodePtr *topPtr,char info){ //same old push function
   StackNodePtr newPtr = malloc(sizeof(StackNode));

   if (newPtr != NULL){
       newPtr->data = info;
       newPtr->nextPtr = *topPtr;
       *topPtr = newPtr;
   }
   else {
       printf("%c not inserted, no memory\n", info);
   }
}

bool pop(StackNodePtr *topPtr, char *c){
    /*
        I decided to use bool output for check function to be simpler
    */
    StackNodePtr tempPtr = *topPtr;
    if(tempPtr == NULL){
        return false; //is the top of stack is NULL ie, stack is empty
    }
    //else ->
    *c = tempPtr->data; //pointer to char
    *topPtr = tempPtr->nextPtr; //go to next pointer
    free(tempPtr); //pop the last pointer
    return true;
}

void printStack(char string[100], int result){ //uses result from check function
    printf("\"%s\"",string); //prints the original string

    if (result == 1){ //
        printf("%s"," is a palindrome"); } //according to result output is promted
    else {
        printf("%s"," is not a palindrome"); }
}



int check(StackNodePtr *topPtr, char string[100] ){
    char c;
    int i =0;
    while(pop(topPtr,&c)){ //checks if top stack is not NULL
        if( string[i] != " " ){ //ignores spaces
            if (c != string[i++] ){ //if element doesnt not match
                return 0; //return 0 and end this function
            }
        }
    }
    return 1; //if every element is found, return 1
}
