/* 
cc2.3: Implement an algorithm to delete a node in the middle (i.e., any node
       but the first and last node, not necessarily the exact middle) of a
       singly linked list, given only access to that node.

EXAMPLE
       Input: the node c from the linked list a->b->c->d->e->f
       Output: nothing,but a new linked list a->b->d->e->f


思路：（有点小tricky，注意！！）复制next node的val给当前的node，然后把next node删掉。这里
      可以理解为不是要求删掉某个特定位置的node，而是删掉拥有某个特定val的node。因为是删到next
      node，所以该算法不适用于最后一个node（需要告诉interviewer！！）。

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
	int i;
	int len=strlen(a);
	struct Node *head, *tail, *s;
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


struct Node *search(struct Node *head, char x)
{
	struct Node *p;
	p=head->next;
	while(p!=NULL&&p->val!=x)
		p=p->next;
	return p;
}

/* Time:O(1), Extra Space:O(1) */
void delete(struct Node *p)
{
	struct Node *cur;
	if(p==NULL|p->next==NULL)
	{
		printf("\nNot able to delete the node!\n");
		return;
	}
    cur=p->next;
    p->val=cur->val;
    p->next=cur->next;
    free(cur);
}


void main()
{
	char a[]="abcdef";
	struct Node *head, *del, *p, *cur;
	head=create(a);
	p=head->next;
    del=search(head, 'c');
    delete(del);
    while(p!=NULL)
    {
    	printf("%c ", p->val);
    	p=p->next;
    }
    printf("\n\n");
    while(head!=NULL)
    {
    	cur=head;
    	head=head->next;
    	free(cur);
    }
}


