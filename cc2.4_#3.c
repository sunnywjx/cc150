#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 7

typedef struct Node
{
    int val;
    struct Node *next;
}Node;

Node *initial()
{
    Node *head;
    head=(Node *)malloc(sizeof(Node));
    if(head==NULL)
        return NULL;
    head->next=NULL;
    return head;
}

Node *create(int a[])
{
    Node *head, *tail, *s;
    int i;
    head=initial();
    tail=head;
    for(i=0; i<N; i++)
    {
        s=(Node *)malloc(sizeof(Node));
        if(s==NULL)
            return NULL;
        s->val=a[i];
        s->next=NULL;
        tail->next=s;
        tail=s;
    }
    return head;
}

Node *partition(Node *head, int x)
{
    Node *tail, *s, *cur, *p;
    tail=head;
    p=head;
    int len=0;
    while(tail->next!=NULL)
    {
        len++;
        tail=tail->next;
    }
    while(len>0)
    {
        if(p->next->val<x)
            p=p->next;
        else
        {
            s=(Node *)malloc(sizeof(Node));
            s->val=p->next->val;
            cur=p->next;
            p->next=cur->next;
            free(cur);
            tail->next=s;
            s->next=NULL;
            tail=s;
        }
        len--;
    }
    return head;
}


void main()
{
    int a[N]={3,4,8,5,9,2,1};
    int x;
    Node *head, *newhead=NULL, *p, *cur;
    
    head=create(a);
    newhead=partition(head, 5); 
    p=newhead->next;
           
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