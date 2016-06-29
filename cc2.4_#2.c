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

Node *partition(int a[], int x)   // no empty head
{
    Node *head=NULL, *tail=NULL, *s;
    s=(Node *)malloc(sizeof(Node));
    s->val=a[0];
    s->next=head;
    head=s;
    tail=head;
    int i;
    for(i=1; i<N; i++)
    {
        if(a[i]<x)
        {
            s=(Node *)malloc(sizeof(Node));
            s->val=a[i];
            s->next=head;
            head=s;
        }
        else
        {
            s=(Node *)malloc(sizeof(Node));
            s->val=a[i];
            s->next=NULL;
            tail->next=s;
            tail=s;
        }
    }
    return head;
}


void main()
{
    int a[N]={3,4,8,5,9,2,1};
    int x;
    Node *head, *p, *cur;
    
    head=partition(a, 5); 
    p=head;
           
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
    printf("hello\n");
    
}