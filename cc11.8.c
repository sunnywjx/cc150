/*
cc11.8: Imagine you are reading in a stream of integers. Periodically, you wish to be able to look up the rank of
        a number x(the number of values less than or equal to x). Implement the data structures and algorithms to
        support these operations. That is, implement the method track(int x), which is called when each number is 
        generated, and the method getRankOfNumber(int x), which returns the number of values less than or equal to
        x(not including x itself).


IDEA:                           5(5)
                               /    \
                              /      \
                             /        \
                          1(0)        9(1)
                             \        /  \
                              \      /    \
                               \    /      \
                              4(2) 7(0)   13(0)
                              /  \
                             /    \
                            /      \
                          4(1)    5(0)
                          /   
                         /       
                        /       
                      3(0)    

        We are using a binary search tree to store the number and the num of nodes at the left side, thus both 
    track(int x) and getRankOfNumber(int x) cost O(logN) time.

    int getRankOfNumber(RankNode node, int x)
    {
	    if x is node->data, return node->leftSize;
	    if x is on left of node, return node->left->leftSize;
        if x is on right of node, return node->leftSize+1+getRankOfNumber(node->right, x).
    }

*/ 

#include <stdio.h>
#include <stdlib.h>   

typedef struct RankNode
{
	int left_size;
	struct RankNode *left;
	struct RankNode *right;
	int data;
}RankNode;

RankNode *create(int x)
{
	RankNode *node;
	node=(RankNode *)malloc(sizeof(RankNode));
	node->left_size=0;
	node->left=NULL;
	node->right=NULL;
	node->data=x;
	return node;
}



RankNode *insert(RankNode *root, int d)
{
	if(d<=root->data)
	{
		if(root->left!=NULL)
			root->left=insert(root->left, d);
		else
			root->left=create(d);
		root->left_size++;
	}
	else
	{
		if(root->right!=NULL)
			root->right=insert(root->right, d);
		else
			root->right=create(d);
	}
	return root;
}


RankNode *track(RankNode *root, int number)
{
	if(root==NULL)
		return create(number);		
	else
		return insert(root, number);
}

int getRankOfNumber(RankNode *root, int number)
{
	if(number==root->data)
		return root->left_size;
	else if(number<root->data)
	{
		if(root->left==NULL)
			return -1;
		else
			return getRankOfNumber(root->left, number);
	}
	else
	{
		int right_rank=root->right==NULL? -1:getRankOfNumber(root->right, number);
		if(right_rank==-1)
			return -1;
		else
			return root->left_size+1+right_rank;
	}
}


void freeTree(RankNode *root)
{
	if(root!=NULL)
	{
		freeTree(root->left);
	    freeTree(root->right);
	    free(root);
	}	  
}


void main()
{
	RankNode *root=NULL;

	root=track(root, 5);
	root=track(root, 1);
	
	root=track(root, 4);
	root=track(root, 4);
	root=track(root, 5);
	root=track(root, 9);
	root=track(root, 7);
	root=track(root, 13);
	root=track(root, 3);
	/*
	printf("%d\n", root->left_size);
	printf("%d\n", root->left->left_size);
	printf("%d\n", root->left->right->left_size);
	printf("%d\n", root->left->right->left->left_size);
	printf("%d\n", root->left->right->right->left_size);
	printf("%d\n\n", root->left->right->left->left->left_size);
	
	printf("%d\n", root->right->left_size);
	printf("%d\n", root->right->left->left_size);
	printf("%d\n", root->right->right->left_size);
	*/

	printf("%d\n", getRankOfNumber(root, 1));
	printf("%d\n", getRankOfNumber(root, 3));
	printf("%d\n", getRankOfNumber(root, 13));

	freeTree(root);
}     