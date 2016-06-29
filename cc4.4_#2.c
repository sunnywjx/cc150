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

typedef struct Queue
{
	int capacity;
    int size;
    int front;
    int rear;
    Tnode *elements[N*5];
}Queue;

Queue *CreateQueue()
{   
    Queue *Q;
    Q = (Queue *)malloc(sizeof(Queue));    
    //Q->elements = (Tnode *)malloc(sizeof(Tnode)*N*5);
    Q->size = 0;
    Q->capacity = N*5;
    Q->front = 0;
    Q->rear = -1;
    return Q;
}

void Dequeue(Queue *Q)
{
    if(Q->size==0)
    {
        printf("Queue is Empty\n");
        return;
    }
    else
    {
        Q->size--;
        Q->front++;
        if(Q->front==Q->capacity)
        {
        	Q->front=0;
        }    
    }
    return;
}

Tnode *Front(Queue *Q)
{
    if(Q->size==0)
    {
        printf("Queue is Empty\n");
        exit(0);
    }
    return Q->elements[Q->front];
}

void Enqueue(Queue *Q,Tnode *node)  //need to store the TreeNode in the queue
{
    if(Q->size == Q->capacity)
        printf("Queue is Full\n");
    else
    {
        Q->size++;
        Q->rear++;
        if(Q->rear == Q->capacity)
        {
        	Q->rear = 0;
        }    
        Q->elements[Q->rear] = node;
    }
    return;
}

LLnode *ht[N];
void ListOfDepths2(Tnode *root)
{
	int curNum=1, nextNum=0, level=0;   
	Queue *Q=CreateQueue();
	Enqueue(Q, root);
	while(Q->size)
	{
		Tnode *curNode=Front(Q);
		Dequeue(Q);
		curNum--;
		if(curNode->left!=NULL)
		{
			Enqueue(Q, curNode->left);
			nextNum++;
		}
		if(curNode->right!=NULL)
		{
			Enqueue(Q, curNode->right);
			nextNum++;
		}
		LLnode *s=createL(curNode->val);
	    s->next=ht[level];	
	    ht[level]=s;
		
		if(curNum==0)
		{
			level++;
			curNum=nextNum;
			nextNum=0;
		}
	}
	free(Q);
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
	ListOfDepths2(n2);

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