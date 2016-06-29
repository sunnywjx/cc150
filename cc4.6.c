/*
cc4.6: Write an algorithm to find the "next" node(i.e., in-order successor) of a given node in a 
       binary search tree. You may assume that each node has a link to its parent.

IDEA: 1. if we are doing an in-order traversal, the successor is the leftmost node in the right 
         branch tree; 
      2. if a node dosen't have a right branch tree, go to check its parents till it is at the 
         parent's left branch tree.
*/




#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	struct TreeNode *parent;
}TreeNode;

TreeNode *create(int x)
{
	TreeNode *node;
	node=(TreeNode *)malloc(sizeof(TreeNode));
	node->val=x;
	node->left=NULL;
	node->right=NULL;
	node->parent=NULL;
	return node;
}

TreeNode *successor(TreeNode *node)
{
	if(node==NULL)
		return NULL;
	if(node->right!=NULL)
	{
		node=node->right;
		while(node->left!=NULL)
			node=node->left;
	}
	else
	{
		//TreeNode *next=node->parent;
		while(node->parent!=NULL&&node->parent->left!=node)
			node=node->parent;
		node=node->parent;
	}
	return node;
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
	//n1->right=n2;
	n1->parent=n3;

	n5->left=n4;
	n5->right=n6;
	n5->parent=n3;

	n0->parent=n1;
	//n2->parent=n1;
	n4->parent=n5;
	n6->parent=n5;

    printf("Successor is: %d\n", successor(n1)->val);
    printf("Successor is: %d\n", successor(n4)->val);
    printf("Successor is: %d\n", successor(n5)->val);
    printf("Successor is: %d\n", successor(n0)->val);
    printf("Successor is: %d\n", successor(n3)->val);

    free(n0);
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    free(n6);

}