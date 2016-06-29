/*
cc9.4: Write a method to return all subsets of a set.


IDEA:  1. Every element has two choice: in the subset or not in the subset; this can be represented by a binary
          string. (e.g., 011--{  2, 3}, 101--{1,  3}). (Cannot deal with duplicate elements!!)

*/

#include <stdio.h>
#include <stdlib.h>
#define N 3

typedef struct Node
{
	int val;
	struct Node *next;
}Node;

Node *create(int x)
{
	Node *node;
	node=(Node *)malloc(sizeof(Node));
	node->val=x;
	node->next=NULL;
	return node;
}

Node *getTail(Node *node)
{
	Node *p=node;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	return p;
}


// Time: O(n*2^n) 
void getSubsets(int set[], Node *ht[])
{
	int max=1<<N;  //pow(2, N)
	int i, j;	
	for(i=0; i<max; i++)
	{
		int cur=0;
		for(j=i; j>0; j>>=1)
		{
			if(j&1>0)
			{
				Node *s=create(set[cur]);
				Node *tail=getTail(ht[i]);
				tail->next=s;	
			}
			cur++;	
		}
	}
}


void freeList(Node *ht[])
{
	Node *cur;
	int i;
	int M=1<<N;
	for(i=0; i<M; i++)
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
	int set[N]={1, 2, 3};
	int i, j;
	int M=1<<N; //pow(2, N)
	Node *ht[M];
    for(i=0; i<M; i++)
	{
		ht[i]=(Node *)malloc(sizeof(Node));
		ht[i]->next=NULL;
	}
	getSubsets(set, ht);
	printf("The subsets are: \n");
	for(i=0; i<M; i++)
	{
		Node *p=ht[i]->next;
		printf("{ ");
		while(p!=NULL)
		{
			printf("%d ", p->val);
			p=p->next;
		}
		printf("}\n");
	}
	freeList(ht);
}


