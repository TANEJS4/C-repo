//Author: Shivam taneja

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// self-referenced structure
struct stackNode {
	int data;
	struct stackNode *nextPtr;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

// prototypes
void push(StackNodePtr *topPtr, int info);
int pop(StackNodePtr *topPtr, int iter);
void printStack(StackNodePtr currentPtr);
int main(void){
	StackNodePtr stackPtr = NULL;
    int count = 0;
	char value[100];
	printf("%s","Stack[] = [");
    fgets(value,100,stdin);
    int i =0, j =0;
    int lent = (int) sizeof(value) / sizeof(value[0]);
    for( i =0; i < lent ; i++){
        if(isdigit(value[i])) {
            count++;
            push(&stackPtr,(int) value[i]);
        }
        else{
            continue;
        }
    }
    if(count%2==0){
        count = count / 2;
    }
    else {
        count = 1 + count ;
        count = count / 2;
    }
    printStack(stackPtr);

    puts("\n");
    pop(&stackPtr, count);
    printStack(stackPtr);
}

void push(StackNodePtr *topPtr,int info){
	StackNodePtr newPtr = malloc(sizeof(StackNode));

	if (newPtr != NULL){
		newPtr->data = info;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	}
	else {
		printf("%d not inserted, no memory\n", info);
	}
}
int pop(StackNodePtr *topPtr, int iter){
    StackNodePtr tempPtr = *topPtr;
    while(iter != 0){
        iter--;
    	(*topPtr) =(*topPtr)->nextPtr;
    }
    int popValue = (*topPtr)->data;
    free(tempPtr);
    return popValue;
}
void printStack(StackNodePtr currentPtr){
	if(currentPtr == NULL) {
		puts("The stack is empty\n");
	} else {
		printf("%s","Stack[] = [");
		while(currentPtr != NULL) {
			printf("%d",currentPtr->data );
			currentPtr = currentPtr->nextPtr;
            printf("%s"," " );

		}
		printf("%s","]");
	}
}
