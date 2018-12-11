//Author : Shivam Taneja
#include<stdio.h>
#include <string.h>
#include <stdlib.h>

// A tree node structure
struct treeNode
{
  int data;
  struct treeNode *leftPtr;
  struct treeNode *rightPtr;
};
typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;


//prototypes
void insert(TreeNodePtr *treePtr, int info);
void printTree(TreeNodePtr root, int key1, int key2);


// struct treeNode* newNode(int data){
//   TreeNodePtr tempPtr = malloc(sizeof(TreeNode));
//   tempPtr->data = data;
//   tempPtr->leftPtr = NULL;
//   tempPtr->rightPtr = NULL;
//
//   return tempPtr;
// }

// Driver function to test above functions
int main(){
  TreeNodePtr startPtr = NULL;
  int node;
  unsigned key1, key2;

  puts("enter parent(root) element__ end with -1: ");
  scanf("%d",&node );
  insert(&startPtr,node);

  while( node != (-1) ) {
      printf("%s","\nenter element: ");
      insert(&startPtr,node);
      scanf("%d", &node);
  }

  printf("%s", "\nEnter key1:");
  scanf("%d", &key1);
  printf("%s", "\nEnter key2:");
  scanf("%d", &key2);

  // Constructing tree given in the above figure


  printTree(startPtr, key1, key2);


}


// The functions prints all the keys which in the given range [key1..key2].
void printTree(TreeNodePtr root, int key1, int key2){
   // base case
   if ( NULL == root )
      return;

   // Since the desired o/p is sorted, recurse for left subtree first

   if ( key1 < root->data ){
     printTree(root->leftPtr, key1, key2);
}
   // if root's data lies in range, then prints root's data
   if ( key1 <= root->data && key2 >= root->data ){
     printf("%d ", root->data );
}
  // If root->data is smaller than key2, then only we can get  keys in right subtree
   if ( key2 > root->data ){
     printTree(root->rightPtr, key1, key2);
 }
}


// function to create a Binary Tree

void insert(TreeNodePtr *treePtr, int info){
    if (*treePtr == NULL){
        (*treePtr) = malloc(sizeof(TreeNode));

        if (*treePtr != NULL){
            (*treePtr)->data = info;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        } else {
            printf("%c not inserted. No memory available", info);

        }
    } else {
        if(info < (*treePtr)->data){
            insert(&((*treePtr)->leftPtr), info);
        } else if(info > (*treePtr)->data){
            insert(&((*treePtr)->rightPtr), info);
        }
    }
}
