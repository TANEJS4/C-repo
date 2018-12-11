//Author: Shivam taneja

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// self-referenced structure
struct stackNode {
	char data;
	struct stackNode *nextPtr;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

// prototypes
void push(StackNodePtr *topPtr, char info);
void pop(StackNodePtr *topPtr);
void printStack(StackNodePtr currentPtr);

int main(){
	StackNodePtr stackPtr = NULL;
	char *e, value[100], reverse[100];
	printf("%s","Prefix : ");
    fgets(value,100,stdin);
	int j = 0, i = 0;
	int len = strlen(value);

  	for (i = len - 1; i >= 0; i--){
  		reverse[j++] = value[i];
  	}
  	reverse[i] = '\0';
	e = reverse;

	while(*e != '\0'){
		if (isalnum(*e)){
			push(&stackPtr,*e);
		} else {
			pop(&stackPtr);
			pop(&stackPtr);
		}
		e++;
	}
	puts("Postfix : ");
	printStack(stackPtr);
}



void push(StackNodePtr *topPtr, char info){
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
void pop(StackNodePtr *topPtr){
    StackNodePtr tempPtr = *topPtr;
	*topPtr = (*topPtr)->nextPtr;
	free(tempPtr);
}

void printStack(StackNodePtr currentPtr){
	if(currentPtr == NULL) {
		puts("The stack is empty\n");
	} else {
		while(currentPtr != NULL) {
			printf("%c",currentPtr->data );
			currentPtr = currentPtr->nextPtr;

		}
	}
}
