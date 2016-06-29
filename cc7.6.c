/*
cc7.6: Given a two-dimensional graph with points on it, find a line which passes the most
       number of points.


IDEA: We use ht[(int)(fabs(slope)/epsilon)] hash table to store the information of lines. 
      Thus, this algorithm cannot deal with x=1(cuz slope is infinity!!) and any slope that
      beyond 10(cuz we use ht[100]).
      Besides, floating point numbers cannot always be represented accurately in binary. 
      We resolve this by checking three spots in the hashtable: key, key-epsilon, key+epsilon.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 4 //number of points

double epsilon=0.1;
typedef struct points
{
	double x;
	double y;
}Point;

typedef struct Line
{
	double slope;
	double y_intercept;
}Line;

Point CreatePoint(double x, double y)
{
	Point p;
	p.x=x;
	p.y=y;
	return p;
}

Line CreateLine(Point a, Point b)
{
	Line l;
	l.slope=(a.y-b.y)/(a.x-b.x);
	l.y_intercept=(a.x*b.y-a.y*b.x)/(a.x-b.x);
	return l;
}

typedef struct LinkedList
{
	double s;
	double y;
	struct LinkedList *next;
}Node;

Node *CreateNode(double s, double y)
{
	Node *node;
	node=(Node *)malloc(sizeof(Node));
	node->s=s;
	node->y=y;
	node->next=NULL;
	return node;
}

int isEquivalent(double y1, double y2)
{
	if(abs(y1-y2)<epsilon)
		return 1;
	else return 0;
}


int countEquivalentLines(Node *hash, Line line)
{
	int count=0;
	Node *p=hash->next;
	while(p)
	{
		if(isEquivalent(line.y_intercept, p->y)&&isEquivalent(line.slope, p->s))
			count++;
		p=p->next;
	}
	return count;
}

int floorToNearestEpsilon(double d)
{
	return (int)(fabs(d)/epsilon);   //d=3.57, r=35
}

int countTotalLines(Node *ht[], Line line)
{
	int key=floorToNearestEpsilon(line.slope);
	int count;
	if(key==0)
		count=countEquivalentLines(ht[key], line)+countEquivalentLines(ht[key+1], line);
	else if(key==100)
		count=countEquivalentLines(ht[key], line)+countEquivalentLines(ht[key-1], line);
	else
		count=countEquivalentLines(ht[key], line)+countEquivalentLines(ht[key+1], line)+countEquivalentLines(ht[key-1], line);
    return count;
}



Node *getTail(Node *head)
{
	Node *tail=head;
    while(tail->next!=NULL)
    	tail=tail->next;
    return tail;
}


void insertLine(Node *ht[], Line line)
{
	int key=floorToNearestEpsilon(line.slope);
    //printf("%d\n", key);
    Node *node=CreateNode(line.slope, line.y_intercept);
    node->next==NULL;
	if(ht[key]->next==NULL)
	{
        ht[key]->next=node;
	}
	else
	{
		Node *tail=getTail(ht[key]);
		//printf("Tail is %lf, %lf\n", tail->s, tail->y);
		tail->next=node;
	}
}


Line FindLine(Point array[], Node *ht[])
{
	Line bestLine;
	int bestCount=0;
	int i, j;
	for(i=0; i<N; i++)
	{
		for(j=i+1; j<N; j++)
		{
			Line line=CreateLine(array[i], array[j]);
			//printf("point[%d] and point[%d], slope= %lf, y= %lf\n", i, j, line.slope, line.y_intercept);
			insertLine(ht, line);
			int count=countTotalLines(ht, line);
			//printf("count= %d\n", count);
			if(count>bestCount)
			{
				bestLine=line;
				bestCount=count;
			}
		}
	}
	//printf("bestCount=%d\n", bestCount);
	return bestLine;
		
}

void freeList(Node *ht[])
{
	int i;
	Node *cur;
	for(i=0; i<100; i++)
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
	Node *ht[100];
	int i;
	for(i=0; i<100; i++)
	{
		ht[i]=(Node *)malloc(sizeof(Node));
		ht[i]->next=NULL;
	}
	Point array[N]={CreatePoint(1, 1), CreatePoint(2, 2), CreatePoint(3, 3), CreatePoint(4, 1)};
	Line l;
	l=FindLine(array, ht);
	printf("The line that passes most number of nodes is:\n %lfx + %lf = y\n\n", l.slope, l.y_intercept);
    freeList(ht);
}








