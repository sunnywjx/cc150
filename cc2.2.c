/*
cc2.2: Implement an algorithm to find the kth to last element of a singly
       linked list.
       e.g., second to last(the one before last).
要求：singly linked list。
思路：1. 使用p指针扫描链表的长度，把q指针挪到N－k＋1的位置，返回q。
     2. 使用Runner方法，设置p,q两个指针间隔k-1个位置，当q到达链表最后，
        则p指向的就是倒数第k个元素。


int foo1(void)
{
    int p;
    p = 99;
    return p;
}
  For foo1(), you return a copy of the local variable, not the local 
variable itself.
  

char *foo2(void)
{
    char buffer[] = "test_123";
    return buffer;
}
  For foo2(), you return a copy of a pointer to a local variable. However,
that local variable is deallocated when the function finishes, meaning that
it can and will be reused for other things. Thus, references to that space
are going to wind up pointing to something completely unrelated.



*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node
{
	char val;
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

struct Node *create(char a[])
{
	struct Node *head, *tail, *s;
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
		tail=s;
	}
	return head;
}

/* Time:O(n), Extra Space:O(1) */
struct Node *findKth1(struct Node *head, int k)
{
	int length=0;
	int i;
	struct Node *p, *q;
	p=head->next;
	q=head->next;
    while(p!=NULL)
    {
    	length++;
    	p=p->next;
    }
    /*while(p->next!=NULL)
    {
    	p=p->next;
    	length++;
    }*/
    for(i=1; i<length-k+1; i++)
    	q=q->next;
    return q; /* q is not a pointer that pointing to a local variable, 
                 thus there is no need to allocate memory for q. */
}

/* Time:O(n), Extra Space:O(1) */
struct Node *findKth2(struct Node *head, int k)
{
	struct Node *p, *q;
	int i;
	p=head->next;
	q=head->next;
	for(i=1; i<k; i++)
		q=q->next;
	while(q->next!=NULL)
	{
		p=p->next;
		q=q->next;
	}
	return p;	
}


void main()
{
	struct Node *head, *p, *cur;
	int k=5;
	char a[]="abcdefg";
	if(k==0)
	{
		printf("No such element!\n");
		return;
	}
	head=create(a);
	p=findKth1(head, k);
	printf("%c\n", p->val);
	while(head!=NULL)
	{
		cur=head;
		head=head->next;
		free(cur);
	}
}
