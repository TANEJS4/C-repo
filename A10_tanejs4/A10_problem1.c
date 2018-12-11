//Author : shivam taneja
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stackNode{
    int data;
    struct stackNode *nextPtr;
};

struct queueNode{
    struct stackNode *stack;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;


typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

//prototypes
void push(StackNodePtr *topPtr, int info);
int pop(StackNodePtr *topPtr);
void instructions(void);
int deQue(QueueNodePtr q);
void enQue(QueueNodePtr q, int x);
void printQueue(QueueNodePtr currentPtr);



int main(){
    QueueNodePtr qPtr = malloc(sizeof(QueueNode));
    qPtr->stack = NULL;

    int item;
    int choice;

    instructions();
    scanf("%d", &choice);

    while(choice != 3){
        switch (choice) {
            case 1:
                printf("%s","\nEnter number to queue : ");
                scanf("%d", &item);
                enQue(qPtr, item);
                break;
            case 2:
              printf("\n%d has been removed from the top", deQue(qPtr));
                break;
            default:
                puts("Invalid choice");
                exit(1);
                break;
        }
        instructions();
        scanf("%d", &choice);
    }
}

void enQue(QueueNodePtr q, int x){
    push(&q->stack, x);
}

int deQue(QueueNodePtr qPtr){
    int x, res;
    if(qPtr->stack == NULL ){
        puts("Q is empty");
        exit(1);
    } else if (qPtr->stack->nextPtr == NULL){
        x = pop(&qPtr->stack);
        return x;
    } else {
        x = pop(&qPtr->stack);
        res = deQue(qPtr);
        push(&qPtr->stack, x);
        return res;
    }
}

void push(StackNodePtr *topPtr,int info){ //same old push function
   StackNodePtr newPtr = malloc(sizeof(StackNode));

   if (newPtr != NULL){
       newPtr->data = info;
       newPtr->nextPtr = *topPtr;
       *topPtr = newPtr;
   } else {
       printf("%d not inserted, no memory\n", info);
   }
}

int pop(StackNodePtr *topPtr){

    int res;
    struct stackNode* top;
    // If stack is empty then error
    if (*topPtr == NULL) {
        printf("Stack underflow \n");
    }
    else {
        top = *topPtr;
        res = top->data;
        *topPtr = top->nextPtr;
        free(top);
        return res;
    }
}
void instructions(void){
    printf("%s","\n\nEnter your choice:\n1 to queue an element.\n2 to dequeue top element\n3 to end.\n? ");
}
