#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 7

typedef struct Node
{
    int val;
    struct Node *next;
}Node;

Node *create(int a[])
{
    Node *head=NULL;
    Node *s;
    int i;
    for(i=0; i<N; i++)
    {
        s=(Node *)malloc(sizeof(Node));
        s->val=a[i];
        s->next=head;
        head=s;
    }
    return head;
}

Node *partition(Node *head, int x)   // no empty head
{
	Node *p=head, *tail, *s;
	Node *before=NULL, *after=NULL;
    while(p!=NULL)
    {
    	if((p->val)<x)
    	{
    		s=(Node *)malloc(sizeof(Node));
    		s->next=before;
    		s->val=p->val;
    		before=s;
    	}
    	else
    	{
    		s=(Node *)malloc(sizeof(Node));
    		s->next=after;
    		s->val=p->val;
    		after=s;
    	}
        p=p->next;

    }
    tail=before;
    while(tail->next!=NULL)
    	tail=tail->next;
    tail->next=after;
    return before;
}

void main()
{
    int a[N]={3,4,8,5,9,2,1};
    int x;
    Node *head, *newhead=NULL, *p, *cur;
    
    head=create(a);
    newhead=partition(head, 4); 
    p=newhead;
           
    while(p!=NULL)
    {
        printf("%d ", p->val);
        p=p->next;
    }
    printf("\n");
    while(head!=NULL)
    {
        cur=head;
        head=head->next;
        free(cur);
    }
    while(newhead!=NULL)
    {
        cur=newhead;
        newhead=newhead->next;
        free(cur);
    }
}