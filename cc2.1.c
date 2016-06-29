/*
cc2.1: Write code to remove duplicates from an unsorted linked list. 
       FOLLOW UP: How would you solve this problem if a temporary buffer is not allowed?

要求：Singly Linked List or Doubly Linked List?
     Assume it is Doubly Linked List.

思路：1.如果有temporary buffer，可以使用hash table的概念。把linked list中的字符依次
       存入array里对应的ascii index，遇到重复的字符则删去，需要array[256](use the exact node)。
     2.同上(use the prev node)。
     3.如果没有temporary buffer，则使用两个指针，采用“runner”技术进行一一对比(use the prev node)。

 In C, struct cannot include a function, which in C++, it can.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
	char val;
	struct Node *next;
	struct Node *prev;
};

struct Node *initial()
{
	struct Node *head;
	head=(struct Node *)malloc(sizeof(struct Node));
	if(head==NULL)
		return NULL;
	else
	{
		head->next=NULL;
		head->prev=NULL;
	}
	return head;
}

struct Node *create(char a[])
{
	struct Node *head=NULL, *tail=NULL, *s=NULL;
	int i;
	int len=strlen(a);
	head=initial();
	tail=head;
	for(i=0; i<len; i++)
	{
		s=(struct Node *)malloc(sizeof(struct Node));
                if(s==NULL)
                    return NULL;
		s->val=a[i];
		s->next=NULL;
		tail->next=s;
		s->prev=tail;
		tail=s;
	}
	return head;
}

/* Time:O(n), Extra Space:O(1) use extra buffer */
void delDup1(struct Node *head)  /* use the exact node */
{
	int array[256]={0};
	struct Node *q, *s;
	q=head->next;
	while(q!=NULL)
	{
		if(array[q->val]==0)
			array[q->val]=1;
		else if(q->next==NULL)
		{
			s=q;
            q=q->prev;
            q->next=NULL;
			free(s);    
		}
        else
        {
            s=q;
            q=q->prev;
			q->next=s->next;
			s->next->prev=q;
			free(s);
        }
        q=q->next;
	} 
}


/* Time:O(n), Extra Space:O(1) use extra buffer */
void delDup2(struct Node *head) /* use the prev node */
{
	int array[256]={0};
	struct Node *q, *s;
	q=head;
	while(q->next!=NULL)
	{
		if(array[q->next->val]==0)
        {
			array[q->next->val]=1;
            q=q->next;
        }
		else if(q->next->next==NULL)
		{
			s=q->next;
            q->next=NULL;
			free(s);    
		}
        else
        {
            s=q->next;
            q->next=s->next;
			s->next->prev=q;
			free(s);
        }
	}
}



/* Time:O(n^2), Extra Space:O(1) no extra buffer used */
void delDup3(struct Node *head)
{
	struct Node *p, *q, *s;
	p=head->next;
	while(p!=NULL) /* cannot use p->next!=NULL cuz for char a[]="aa", if p 
point to the first 'a', and we delete the second 'a', then suddenly p=p->next
will let p=NULL, then when we check p->next!=NULL wrong thing will happen. */
	{
		q=p;
		while(q->next!=NULL) /* find the prev node of the dup node */
		{
	        if(q->next->val!=p->val)
                q=q->next;
		    else if(q->next->next==NULL)
            {
            	s=q->next;
                q->next=NULL;
                free(s);  
            }
            else
            {
                s=q->next;
                s->next->prev=q;
			    q->next=s->next;
			    
			    free(s);
            } 
		}
		p=p->next;	 
    }
}



void main()
{  
	char a[]="acabcdffaa"; /* or char a[10]="aabcd"; */
	struct Node *head, *p, *cur;
	head=create(a);
	delDup3(head);
	p=head->next;
	while(p!=NULL)
	{
		printf("%c ",p->val);
		p=p->next;
	}
	printf("\n");
	while(head!=NULL)
	{
		cur=head;
		head=head->next;
		free(cur);
	}

}

