#include <stdio.h>
#include <stdlib.h>

#define N 3

typedef struct LinkedListNode
{
	int val;
	struct LinkedListNode *next;
}LLnode;

typedef struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}Tnode;

LLnode *createL(int x)
{
	LLnode *node;
	node=(LLnode *)malloc(sizeof(LLnode));
	node->val=x;
	node->next=NULL;
	return node;
}

Tnode *createT(int x)
{
	Tnode *node;
	node=(Tnode *)malloc(sizeof(Tnode));
	node->val=x;
	node->left=NULL;
	node->right=NULL;
	return node;
}

LLnode *ht[N];
void ListOfDepths1(Tnode *root, int level)
{
	if(root==NULL)
		return;
	LLnode *node=createL(root->val);
	node->next=ht[level];	
	ht[level]=node;
	ListOfDepths1(root->left, level+1);
	ListOfDepths1(root->right, level+1);
}

void freeList(LLnode *ht[])
{
	int i;
	LLnode *cur;
	for(i=0; i<N; i++)
	{
		while(ht[i]!=NULL)
		{
			cur=ht[i];
			ht[i]=ht[i]->next;
			free(cur);
		}		
	}
}

void main()
{
	LLnode *p;
	Tnode *n0, *n1, *n2, *n3, *n4, *n5;
	n0=createT(0);
	n1=createT(1);
	n2=createT(2);
	n3=createT(3);
	n4=createT(4);
	n5=createT(5);
	
	n2->left=n0;
	n2->right=n4;
	
	n0->right=n1;

	n4->left=n3;
	n4->right=n5;		

	int i;
	ListOfDepths1(n2, 0);

	for(i=0; i<N; i++)
	{
		p=ht[i];
		while(p!=NULL)
		{
			printf("%d ", p->val);
		    p=p->next;
		}
		printf("\n");	
	}
	
	freeList(ht);
	free(n0);
	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
}