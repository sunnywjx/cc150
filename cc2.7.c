/* 
cc2.7: Given a circular linked list, implement an algorithm that returns the
       node at the beginning of the loops.
DEFINITION
Circular linked list: A (corrupt) linked list in which a node's next pointer 
                      point to an earlier node, so as to make a loop in the 
                      linked list.
EXAMPLE
Input:  A->B->C->D->E->C
Output: C 

思路：1. 使用一个array[256]，类似于hashmap，扫描整个linked list，把字符对应的array处
        设为1，重复出现则判断为loop的起点，输出该起点。(若链表中有重复出现的字符，该方法则
        不适用！！)
     2. 使用slow/fast runner，slow每次move一步，fast每次move两步，最后会相遇。(该方
        法对链表中有重复字符也适用！！)

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node 
{
	char val;
	struct Node *next;
};


struct Node *create()
{
	struct Node *s1, *s2, *s3, *s4, *s5, *s6;
    s1=(struct Node *)malloc(sizeof(struct Node));
    s2=(struct Node *)malloc(sizeof(struct Node));
    s3=(struct Node *)malloc(sizeof(struct Node));
    s4=(struct Node *)malloc(sizeof(struct Node));
    s5=(struct Node *)malloc(sizeof(struct Node));
    s6=(struct Node *)malloc(sizeof(struct Node));
	s1->val='a';
	s1->next=s2;
	s2->val='b';
	s2->next=s3;
	s3->val='c';
	s3->next=s4;
	s4->val='d';
	s4->next=s5;
	s5->val='e';
	s5->next=s6;
	s6->val='f';
	s6->next=s4;
	return s1;
}


struct Node *loopDet1(struct Node *head)
{
	char array[256]={0};
	struct Node *p;
        p=head;
	while(p!=NULL)
	{
		if(array[p->val]==0)
		{
			array[p->val]=1;
			p=p->next;
		}
		else
			break;
	}
	if(p==NULL)
	{
		printf("No loop!\n");
		return head;
	}
        printf("Loop!\n");
	return p; /* p is a pointer that not pointing  to a local variable,thus it
                     is fine to return it and no need to use malloc. */
}


struct Node *loopDet2(struct Node *head)
{
	struct Node *slow, *fast;
	slow=head;
	fast=head;

    /* cannot use slow!=fast, 这样一开始slow=head, fast=head,则根本不会进入循环 */
	while(fast!=NULL&&fast->next!=NULL)                                      
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
			break;
	}

	/* 总共判断了四种情况：1.如果head没有node的话，则不存在loop；如果head只有一个元素
	   并且这个元素指向NULL的话，则没有loop；如果head有even个node，但最后以NULL结尾，
	   则没有loop；如果head有odd个node，最后以NULL结尾，则没有loop。 */
	if(fast==NULL||fast->next==NULL)
	{
		printf("No Loop!\n");
		return NULL;
	}

	/* move slow to the head, keep fast at the collision point, each are k
	   steps from the loop start. Then move them at the same pace, they will
	   finially meet each other. */
	slow=head;
	while(slow!=fast)
	{
		slow=slow->next;
		fast=fast->next;
	}
	return slow; 
	/* or return fast, both now point to the start of the loop */
}


void print(struct Node *head)
{
    struct Node *x;
    int count=7;
    x=head;
    while(count>0)
    {
        printf("%c ",x->val);
        x=x->next;
        count--;
    }
    printf("\n");
}

void freeList(struct Node *head)
{
    struct Node *cur;
    int count=6;
    while(count>0)
    {
        cur=head;
        head=head->next;
        free(cur);
        count--;
    }
}

void main()
{
	struct Node *head, *p;
	head=create();
        
	print(head);
	printf("%c\n",loopDet1(head)->val);
	freeList(head);
}











