/*
cc4.8: You have two very large binary trees: T1 with millions of nodes, and T2 with hundreds of node.
       Create an algorithm to decide whether T2 is a subtree of T1. A tree T2 is a subtree of T1 if 
       there exists a node n in T1 such that the subtree of n is identical to T2. That is,  if you 
       cut off the tree at node n, the two trees would be identical.

IDEA:  Cannot use in-order traversal, need to use pre-order traversal.

*/


#include <stdio.h>
#include <stdlib.h>


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
	TreeNode *node;
	node=(TreeNode *)malloc(sizeof(TreeNode));
	node->val=x;
	node->left=NULL;
	node->right=NULL;
	return node;
}


int compare(TreeNode *T1, TreeNode *T2)
{
	if(T1==NULL&&T2==NULL)
		return TRUE;
	if(T1==NULL||T2==NULL) //one node exists, the other one doesn't exist.
		return FALSE;
	if(T1->val==T2->val)
	{
		return compare(T1->left, T2->left)&&compare(T1->right, T2->right);
	}
	return FALSE;
}


int checkSub(TreeNode *T1, TreeNode *T2)
{
	if(T2==NULL)
		return TRUE;
	if(T1==NULL)
		return FALSE;
	if(T1->val==T2->val&&compare(T1, T2))
		return TRUE;
    return checkSub(T1->left, T2)||checkSub(T1->right, T2);
	
}





void main()
{
 	TreeNode *n0, *n1, *n2, *n3, *n4, *n5, *n6, *n7;
 	TreeNode *n8, *n9, *n10, *n11, *n12, *n13, *n14;
 	TreeNode *m0, *m1, *m2;
 	n0=create(0);
	n1=create(1);
	n2=create(2);
	n3=create(3);
	n4=create(4);
	n5=create(5);
	n6=create(6);
	n7=create(7);
	n8=create(8);
	n9=create(9);
	n10=create(10);
	n11=create(11);
	n12=create(12);
	n13=create(13);
	n14=create(14);

	m0=create(5);
	m1=create(11);
	m2=create(12);

	n0->left=n1;
	n0->right=n2;

	n1->left=n3;
	n1->right=n4;

	n2->left=n5;
	n2->right=n6;

	n3->left=n7;
	n3->right=n8;

	n4->left=n9;
	n4->right=n10;

	n5->left=n11;
	n5->right=n12;

	n6->left=n13;
	n6->right=n14;

	m0->left=m1;
	m0->right=m2;

	printf("T2 is a subtree of T1: %d\n", checkSub(n0, m0));
   
    free(n0);
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    free(n6);
    free(n7);
    free(n8);
    free(n9);
    free(n10);
    free(n11);
    free(n12);
    free(n13);
    free(n14);

    free(m0);
    free(m1);
    free(m2);

}

























