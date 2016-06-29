/*
cc7.7: Design an algorithm to find the kth number such that the only prime factors are 3, 5 
       and 7.

IDEA:

            Q3 = 3
            Q5 = 5
            Q7 = 7

            remove min = 3

            Q3 = 3*3
            Q5 = 5, 3*5
            Q7 = 7, 3*7

            remove min = 5

            Q3 = 3*3
            Q5 = 3*5, 5*5
            Q7 = 7, 3*7, 5*7

            remove min = 7

            Q3 = 3*3
            Q5 = 3*5, 5*5 
            Q7 = 3*7, 5*7, 7*7

            remove min = 3*3

            Q3 = 3*3*3
            Q5 = 3*5, 5*5, 3*3*5
            Q7 = 3*7, 5*7, 7*7, 3*3*7
                    .
                    .
                    .

*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 50
#define MIN(a, b) ((a)<(b)? (a):(b))

typedef struct Queue
{
	int capacity;
    int size;
    int front;
    int rear;
    int element[N];
}Queue;

Queue *CreateQueue()
{   
    Queue *Q;
    Q = (Queue *)malloc(sizeof(Queue));    
    Q->size = 0;
    Q->capacity = N;
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

int Front(Queue *Q)
{
    if(Q->size==0)
    {
        printf("Queue is Empty\n");
        exit(0);
    }
    return Q->element[Q->front];
}

void Enqueue(Queue *Q, int x) 
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
        Q->element[Q->rear] = x;
    }
    return;
}


int getKth(int k)
{
	if(k<=0)
		return -1;
	Queue *Q3, *Q5, *Q7;
	Q3 = CreateQueue();
	Q5 = CreateQueue();
	Q7 = CreateQueue();
	Enqueue(Q3, 1);
	//if(k==1)
	//	return Front(Q3);
    int i;
	int val=0;
	for(i=1; i<=k; i++)
	{
		int v3=Q3->size>0? Front(Q3):INT_MAX;
		int v5=Q5->size>0? Front(Q5):INT_MAX;
		int v7=Q7->size>0? Front(Q7):INT_MAX;
		//printf("Q3=%d, Q5=%d, Q7=%d\n", v3, v5, v7);
        val=MIN(v3, MIN(v5, v7));
        //printf("val=%d\n", val);
        if(val==v3)
        {
        	Dequeue(Q3);
        	Enqueue(Q3, val*3);
        	Enqueue(Q5, val*5);
        	Enqueue(Q7, val*7);
        }
        else if(val==v5)
        {
        	Dequeue(Q5);
        	Enqueue(Q5, val*5);
        	Enqueue(Q7, val*7);
        }
        else if(val==v7)
        {
        	Dequeue(Q7);
        	Enqueue(Q7, val*7);
        }
	}
	free(Q3);
	free(Q5);
	free(Q7);
	return val;

}

void main()
{
	int k;
	for(k=1; k<=13; k++)
	printf("Get %dth number: %d\n", k, getKth(k));

}






