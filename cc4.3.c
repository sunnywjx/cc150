/*
cc4.3: Given a sorted(increasing order) array with unique integer elements, write an algorithm to create
       a binary search tree with minimal height.
*/


#include <stdlib.h>
#include <stdio.h>

#define N 6

typedef struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

TreeNode *create(int x)
{
	TreeNode *node;
	node=(TreeNode *)malloc(sizeof(TreeNode));
	node->val=x;
	node->left=NULL;
	node->right=NULL;
	return node;
}

TreeNode *BST(int src, int des, int array[])
{
	if(src>des)
		return NULL;
	int middle=(des-src)/2+src;
	TreeNode *node;
	
	
	node=create(array[middle]);
	node->left=BST(src, middle-1, array);
	node->right=BST(middle+1, des, array);
	return node;



}

void inOrder(TreeNode *node)
{
    if(node!=NULL)
    {
        inOrder(node->left);
        printf("%d ", node->val);
        inOrder(node->right);
    }
}

void freeTree(TreeNode *node)
{
	if(node->left==NULL&&node->right==NULL)
		free(node);
	else
	{
		if(node->left!=NULL)
			freeTree(node->left)
		if(node->right!=NULL)
			freeTree(node->right);
		free(node);

	}
	
		
}
void main()
{
	int array[N]={0, 1, 2, 3, 4, 6};
	TreeNode *node;
	node=BST(0, N-1, array);
	inOrder(node);
	printf("\n");
	freeTree(node);

}






















