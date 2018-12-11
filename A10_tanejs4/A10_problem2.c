//Author: Shivam Taneja
//help from slides and geekforgeeks
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct treeNode {
	char data;
	struct treeNode* leftPtr;
	struct treeNode* rightPtr;
};
typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

// Prototypes for utility functions
int indexP(char ar[], int start, int end, char val);
TreeNodePtr newNode(char data);


TreeNodePtr insert(char inStr[], char preStr[], int start, int end) {
	static int p = 0;

	if (start > end){
		return NULL;
}
	TreeNodePtr binNode = newNode(preStr[p++]);

	if (start == end){
		return binNode;
	}

	int inIndex = indexP(inStr, start, end, binNode->data);


	binNode->leftPtr = insert(inStr, preStr, start, inIndex - 1);
	binNode->rightPtr = insert(inStr, preStr, inIndex + 1, end);

	return binNode;
}


int indexP(char string[], int start, int end, char val)
{
	unsigned int i;
	for (i = start; i <= end; i++) {
		if (string[i] == val) {
			return i;
		}
	}
}


TreeNodePtr newNode(char data)
{
	TreeNodePtr treeNode = (TreeNodePtr)malloc(sizeof(TreeNode));
	treeNode->data = data;
	treeNode->leftPtr = NULL;
	treeNode->rightPtr = NULL;

	return (treeNode);
}

void print(TreeNodePtr treeNode)
{
	if (treeNode == NULL) {
		return;
	}
	print(treeNode->leftPtr);

	printf("%c ", treeNode->data);

	print(treeNode->rightPtr);
}

int main()
{
	char inOrder[27] = {'D','B','E','A','F','C'};
	char preOrder[27] = {'A','B','D','E','C','F'};
	puts("order sequence:");
	printf("%s\n",inOrder);
	puts("pre order sequence:");
	printf("%s\n",preOrder);

	int len = sizeof(inOrder) / sizeof(inOrder[0]);
	TreeNodePtr root = insert(inOrder, preOrder, 0, len - 1);

	printf("Inorder of the constructed tree is \n");
	print(root);
}
