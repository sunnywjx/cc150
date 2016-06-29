/*
cc4.5: Implement a function to check if a binary tree is a binary search tree.

IDEA: 1. use in-order to traverse the tree, compare the val of pre node and current node!!
         need to return the FALSE or TRUE val from both left and right branch!!(cannot use 
         handle duplicate values, from left to right!!)
      2. use min and max to store the range, everytime check the node whether in the range
         or not, then update the range for the lower level nodes.(from up to down!!) 
*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0

typedef struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

TreeNode *create(int x)
{
	TreeNode *root;
	root=(TreeNode *)malloc(sizeof(TreeNode));
	root->val=x;
	root->left=NULL;
	root->right=NULL;
	return root;
}


int pre=INT_MIN;
int checkBST1(TreeNode *root)
{
	if(root==NULL)
		return TRUE;
	if(!checkBST1(root->left))  //need to keep track of the FALSE from left branch in the tree.
		return FALSE;
	if(pre!=INT_MIN && root->val<=pre)
		return FALSE;
	pre=root->val;
	if(!checkBST1(root->right)) //need to keep track of the FALSE from right branch in the tree.
		return FALSE;
	return TRUE;
}


int checkBST2(TreeNode *root, int min, int max)
{
	if(root==NULL)
		return TRUE;
	if(root->val<=min||root->val>max)
		return FALSE;
	if(!checkBST2(root->left, min, root->val)||!checkBST2(root->right, root->val, max))
		return FALSE;
	return TRUE;
}




void main()
{
	TreeNode *n0, *n1, *n2, *n3, *n4, *n5, *n6;
	n0=create(0);
	n1=create(1);
	n2=create(2);
	n3=create(3);
	n4=create(4);
	n5=create(5);
	n6=create(6);

	n3->left=n1;
	n3->right=n5;

	n1->left=n0;
	n1->right=n2;

	n5->left=n4;
	n5->right=n6;

    printf("checkBST(1--TRUE, 0--FALSE): %d\n", checkBST1(n3));
    printf("checkBST(1--TRUE, 0--FALSE): %d\n", checkBST2(n3, INT_MIN, INT_MAX));

    free(n0);
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    free(n6);

}



















