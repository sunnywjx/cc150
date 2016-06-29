/*
cc4.9: You are given a binary tree in which each node contains an integer value (which might be 
       positive or negative). Design an algorithm to print all paths that sum to a given value 
       and count totoal number of these paths . The path does not need to start or end at the 
       root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

IDEA:  Traverse every route from root, then check valid path backwards.

*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX(a,b) (a>b?a:b)

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

int count;	

void print(int path[], int start, int end)
{
	int i;
	for(i=start; i<=end; i++)
		printf("%d ", path[i]);
	printf("\n");
}

void find_Sum(TreeNode *node, int sum, int path[], int level)
{
	if(node==NULL)
		return;
	path[level]=node->val;
	int t=0;
	int i;
	for(i=level; i>=0; i--)
	{
		t+=path[i];
		if(t==sum)
		{
			count++;
			print(path, i, level);
		}	
	}
	find_Sum(node->left, sum, path, level+1);
	find_Sum(node->right, sum, path, level+1);
}

int depth(TreeNode *node)
{
	if(node==NULL)
		return -1;
	return MAX(depth(node->left), depth(node->right))+1;
}

void findSum(TreeNode *node, int sum)
{
	int N=depth(node)+1;
	int path[N];
    find_Sum(node, sum, path, 0);
}


void main()
{
 	TreeNode *n0, *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8;

 	n0=create(10);
	n1=create(5);
	n2=create(-3);
	n3=create(3);
	n4=create(2);
	n5=create(1);
	n6=create(3);
	n7=create(0);
	n8=create(1);

	n0->left=n1;
	n0->right=n2;

	n1->left=n3;
	n1->right=n4;
	//n1->parent=n0;
	
	n2->right=n5;
	//n2->parent=n0;

	n3->left=n6;
	n3->right=n7;
	//n3->parent=n1;

	n4->right=n8;
	//n4->parent=n1;
	//n5->parent=n2;
	//n6->parent=n3;
	//n7->parent=n3;
	//n8->parent=n4;

    findSum(n0, 8);
	printf("Num of paths = %d\n", count);



    free(n0);
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    free(n6);
    free(n7);
    free(n8);
    
}

/*-------------------------------------------------------------------------------------------------*/
