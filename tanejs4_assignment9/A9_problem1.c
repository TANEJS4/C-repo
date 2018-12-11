//Author: Shivam taneja

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listNode{
    char data;
    struct listNode *nextPtr; //ptr to next node
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;
//prototypes functions
void insert(ListNodePtr *sPtr, char value);
void reverse(ListNodePtr *sPtr);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);


int main(){
    ListNodePtr startPtr = NULL;
    puts("End with *");
    puts("The list is");
    char string[100];
    gets(string); //getting string as array

    for (int i  = 0; string[i]; i++ ){
        if (string[i] != " "){
            insert(&startPtr, string[i]); //pushing each element to the linked list
        }
    }

    reverse(&startPtr); //calling reverse function
    printList(startPtr); //as name suggests, printing list
}

void insert(ListNodePtr *sPtr, char value){ //your casual insert function
                                            //nothing new here
    ListNodePtr newPtr = malloc(sizeof(ListNode));

    if(newPtr != NULL){
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        ListNodePtr previousPtr = NULL;
        ListNodePtr currentPtr = *sPtr;

        while (currentPtr != NULL && value > currentPtr->data ) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        if (previousPtr == NULL){
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        } else {
            previousPtr ->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }

    }
    else {
        printf("%c not inserted. no memory",value );
    }
}

void printList(ListNodePtr currentPtr){
    if(isEmpty(currentPtr)){
        puts("List is empty");
    }
    else {
        puts("The list is:");

        while(currentPtr != NULL){
            printf("%c ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
    }
}
void reverse(ListNodePtr *sPtr){
    ListNodePtr prev   = NULL; //first pointer
    ListNodePtr current = *sPtr;//first pointer to the list pointer
    ListNodePtr next = NULL;//third pointer
    while (current != NULL)
    {
        // Store next
        next  = current->nextPtr;

        // Reverse current node's pointer
        current->nextPtr = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *sPtr = prev;
}

int isEmpty(ListNodePtr sPtr){ //linked list is empty
    return sPtr == NULL;
}
