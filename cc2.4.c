/*
cc2.4: Write code to partition a linked list around a value x, such that all
       nodes less than x come before all nodes greater than or equal to x. If
       x is contained within the list, the values of x only need to be after
       the elements less than x. The partition element x can appear anywhere 
       in th "right partition"; it does not need to appear between the left 
       and right partitions.

思路：1. 已存在一个linked list，新建两个链表，把小于的和大于等于的分别存入两个链表中，再把两
        个新链表merge成一个。
     2. (在没有原始链表的情况下，create the linked list!)在建立该链表的时候，把小于的插
        入head，把大于等于的插入tail。注意需要区分第一个元素的插入后，tail的变化。第一个元素
        无论比x小还是大，插入后，tail都要move一位。之后，每插入一个元素，若是比x小，则头插入，
        tail不用改变位置；若是大于等于x，则尾插入，需要move tail。
     3. (do it in place!)扫描链表，凡是大于等于x的node，则删去并插入尾部，注意while的
        condition不能是p->next!=NULL，因为我们会不断删去并插入；while的condition只能
        是linked list的长度。 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 7

struct Node
{
	int val;
	struct Node *next;
};

struct Node *initial()
{
	struct Node *head;
	head=(struct Node *)malloc(sizeof(struct Node));
	if(head==NULL)
		return NULL;
	head->next=NULL;
	return head;
}

struct Node *create(int a[])
{
	struct Node *head, *tail, *s;
	int i;
	head=initial();
	tail=head;
	for(i=0; i<N; i++)
	{
		s=(struct Node *)malloc(sizeof(struct Node));
		if(s==NULL)
			return NULL;
		s->val=a[i];
		s->next=NULL;
		tail->next=s;
		tail=s;
	}
	return head;
}

/* Time:O(n), Extra Space:O(n) */
struct Node *partition1(struct Node *head, int x)
{
	struct Node *bhead, *btail;
	struct Node *ahead, *atail;
	struct Node *p, *s;
	bhead=initial();
	ahead=initial();
	btail=bhead;
	atail=ahead;
    p=head->next;
	while(p!=NULL)
	{
		s=(struct Node *)malloc(sizeof(struct Node));
		if(s==NULL)
            return NULL;
        s->val=p->val;
        s->next=NULL;
        if((p->val)<x)
		{
			btail->next=s;
			btail=s;
		}
		else
		{
			atail->next=s;
			atail=s;
		}
        p=p->next;
			
	}
	btail->next=ahead->next;
	free(ahead);
	return bhead;		
}

/* Time:O(n), Extra Space:O(n) */
struct Node *partition2(int a[], int x)
{
	struct Node *head, *tail, *s0, *s;
	int i;
	head=initial();
	tail=head;
    s0=(struct Node *)malloc(sizeof(struct Node));
	if(s0==NULL)
	    return NULL;
    s0->val=a[0];
    s0->next=NULL;
	head->next=s0;
    tail=s0;                
	for(i=1; i<N; i++)
	{
		s=(struct Node *)malloc(sizeof(struct Node));
		if(s==NULL)
            return NULL;
        s->val=a[i];
		if(a[i]<x)
		{
            s->next=head->next;
			head->next=s;
		}
		else
		{       
			tail->next=s;
			tail=s;            
		}
	}
	return head;
}


/* Time:O(n), Extra Space:O(1) */
void partition3(struct Node *head, int x)
{
    struct Node *tail, *p, *s, *del;
    int count=0;
    p=head;
    tail=head;   
    while(tail->next!=NULL)
    {
        tail=tail->next;
        count++;
    }
    while(count>0)  /*cannot use p->next!=NULL cuz we continue insert node at the tail*/
    {
        if((p->next->val)<x)
            p=p->next;
        else
        {
            s=(struct Node *)malloc(sizeof(struct Node));
            if(s==NULL)
                return;
            s->val=p->next->val;
            s->next=NULL;
            tail->next=s;
            tail=s;
            del=p->next;
            p->next=del->next;
            free(del);     
        }
        count--;
    }
}



void main()
{
	int a[N]={3,4,8,5,9,2,1};
    int x;
	struct Node *head, *newhead=NULL, *p=NULL, *cur;
    printf("Choose your method through 1 to 3: ");
    scanf("%d", &x);
    switch(x)
    {
        case 1:
            head=create(a);
            newhead=partition1(head, 6); /* create two new linked lists then merge */
            p=newhead->next;
            break;
        case 2:
            head=partition2(a, 6); /* create the linked list */
            p=head->next;
            break;
        case 3:
            head=create(a);
            partition3(head, 6); /* do it in place */
            p=head->next;
            break;
    }   
	
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
