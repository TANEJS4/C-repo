//Author: Shivam taneja

#include <stdio.h>
#include <stdlib.h>
//self-referenced structure
struct listNode{
    int data;
    struct listNode *nextPtr; //ptr to next node
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;
//prototypes functions
void insert(ListNodePtr *sPtr, int value);
void search(ListNodePtr sPtr, int value);
int isEmpty(ListNodePtr sPtr);
void instructions(void);
void printList(ListNodePtr currentPtr);

int main(void){
    ListNodePtr startPtr = NULL;
    int item , choice;

    instructions();
    printf("%s ","? ");
    scanf("%d", &choice);

    while(choice != 3){
        switch (choice) {
            case 1:
                printf("%s","\nEnter number: ");
                scanf("%d", &item);
                insert(&startPtr,item);
                printList(startPtr);
                break;
            case 2:
                printf("%s","\nEnter integer to recursively search for: ");
                scanf("%d", &item);
                search(startPtr,item);
                break;
            default:
                puts("Invalid choice");
                instructions();
                break;
        }
        printf("%s","? ");
        scanf("%d", &choice );

    }
}

void instructions(void){
    puts("Enter your choice:\n"
     "1 to insertItem an element into the list.\n"
     "2 to recursively search list for an element\n"
     "3 to end.");
}
void insert(ListNodePtr *sPtr, int value){
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
        printf("%d not inserted. no memory",value );
    }
}
int isEmpty(ListNodePtr sPtr){
    return sPtr == NULL;
}
void printList(ListNodePtr currentPtr){
    if(isEmpty(currentPtr)){
        puts("List is empty");
    }
    else {
        puts("The list is:");

        while(currentPtr != NULL){
            printf("%d -->", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        puts("NULL1\n");
    }
}
void search(ListNodePtr sPtr, int value){
    ListNodePtr previousPtr = sPtr;
    if(value == previousPtr->data){
        printf("%d is in the list.\n",value);
    } else {
        previousPtr = previousPtr->nextPtr;
        search(previousPtr,value);

        }

}
