/*
cc4.1: Implement a function to check if a binary tree is balanced. For the purposes
       of this question, a balanced tree is defined to be a tree such that the 
       heights of the two subtrees of any node never differ more than one.

IDEA: 1. Get the height for every node, the height of the node is decided by the 
         max height of its subtrees+1. Then, check the balance for node one by one.
      2. Get the height for every node's left and right subtrees, then check the 
         balance. If it is balanced, then return the height of the node; else 
         return a error value. Notice that, the error value cannot be -1, 1 or 0, 
         cuz when the tree is very big, the MAX()+1 will finally vanish the error 
         message. Thus, we choose the INT_MIN!! Also, for the if condition, we 
         need to include lheight==INT_MIN||rheight==INT_MIN for passing error up
         purpose, cuz when two subtrees of one node both return the INT_MIN, then 
         the abs()==0, then the tree will return 1(WRONG)!!

NOTE: 1. The depth of a node is the number of edges from the root to the node.
      2. The height of a node is the number of edges from the node to the deepest 
         leaf. 
      3. && -- if both operands are non-zero (1&&2, -1&&-1), the result is TRUE!!
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX(a,b) (a>b? a:b)

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


struct TreeNode *create(int x)
{
	struct TreeNode *node;
	node=(struct TreeNode *)malloc(sizeof(struct TreeNode));
	node->val=x;
	node->left=NULL;
	node->right=NULL;
	return node;
}

int getHeight(struct TreeNode *root)  //get the height for each node
{
	if(root==NULL)
		return -1;
	else
		return MAX(getHeight(root->left), getHeight(root->right))+1;
}

/* Time: O(N*logN) */
int checkBalanced(struct TreeNode *root) //check each node top to down
{
	if(root==NULL)
		return 1;

	int diff=getHeight(root->left)-getHeight(root->right);

	if(abs(diff)>1)
		return 0;
	else
		return checkBalanced(root->left)&&checkBalanced(root->right);
}

/* Time:O(N) */
int checkHeight(struct TreeNode *root)
{
	if(root==NULL)
		return -1;
	int lheight=checkHeight(root->left);
	int rheight=checkHeight(root->right);
	if(lheight==INT_MIN||rheight==INT_MIN||abs(lheight-rheight)>1)
		return INT_MIN;   /* cannot use -1 or 0 or 1 as error message, cuz MAX()+1
	                         will make this become normal value for height!! */
	else
		return MAX(lheight, rheight)+1;
}



void main()
{
	struct TreeNode *root, *n1, *n2, *n3;
	root=create(0);
	n1=create(1);
	n2=create(2);
	n3=create(3);
	root->right=n1;
	n1->right=n2;
	n2->right=n3;
    printf("%d\n",getHeight(root));
    if(checkBalanced(root))
    	printf("Balanced!\n");
    else
    	printf("Not balanced!\n");

    if(checkHeight(root)!=INT_MIN)
    	printf("Height=%d! Balanced!\n", checkHeight(root));
    else
    	printf("Not balanced!\n");
    free(root);
    free(n1);
    free(n2);
    free(n3);

}

