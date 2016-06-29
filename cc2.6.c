/* 
cc2.6: Implement a function to check if a linked list is a palindrome.

思路：1. 建立一个reverse的链表，与原链表一一比较，如果相同则是palindrome；否则，不是。
     2. 可以建立一个stack来存放改链表的前半段数值，利用LIFO的特性来弹出并和后半段比较。
        如果知道链表长度，可以使用for循环；如果不知道，可以使用runner，一个slow runner，
        一次move一步，一个fast runner，一次move两步。当fast runner hit the end，
        slow runner则hit the middle。Be aware of the while condition!!

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 5

struct Node 
{
	char val;
	struct Node *next;
};

struct Node *create(char a[])
{
	int i;
	int len=strlen(a);
	struct Node *head=NULL, *tail, *s;
    for(i=0; i<len; i++)
    {
    	s=(struct Node *)malloc(sizeof(struct Node));
    	if(s==NULL)
    		return NULL;
    	s->val=a[i];
    	if(head==NULL)
    	{
    		s->next=head;
    		head=s;
    		tail=s;
    	}
    	else
    	{
    		s->next=NULL;
    		tail->next=s;
    		tail=s;
    	}
    }
    return head;
}

struct stack
{
	int capacity;
	int size;
    char *element; /* a string */
};

struct stack *initial()
{
	struct stack *s;
	s=(struct stack *)malloc(sizeof(struct stack));
	s->element=(char *)malloc(sizeof(char)*N);
	s->capacity=N;
	s->size=0;
	return s;
}

void push(struct stack *s, char x)
{
	if(s->size==s->capacity)
		return;
	s->element[s->size]=x;
	s->size++;
	return;
}

void pop(struct stack *s)
{
	if(s->size==0)
		return;
	s->size--;
	return;
}

char top(struct stack *s)
{
	if(s->size==0)
                printf("No element in the stack!\n");
	else
		return s->element[s->size-1];
}

void print(struct Node *head)
{
    struct Node *x;
    x=head;
    while(x!=NULL)
    {
        printf("%c ",x->val);
        x=x->next;
    }
    printf("\n");
}

void palindrome1(struct Node *head)
{
	struct Node *reverse=NULL, *p, *q, *s;
	p=head;
	q=head;
        print(head);
	while(p!=NULL)
	{
		s=(struct Node *)malloc(sizeof(struct Node));
		s->val=p->val;
		s->next=reverse;
		reverse=s;
		p=p->next;
	}
        print(reverse);
	while(q!=NULL)
	{
		if(q->val!=reverse->val)
		{
			printf("No palindrome!\n");
			return;
		}
		else
		{
			q=q->next;
			reverse=reverse->next;
		}	
	}
	printf("palindrome!\n");
        
}


void palindrome2(struct Node *head)
{
	struct Node *slow, *fast;
	struct stack *s;
    s=initial();
	slow=head;
	fast=head;
	if(head->next==NULL)
	{
		printf("The linked list only has one node!\n");
		return;
	}

    /* Be aware of the order, it will always check the 1st condition 
       firstly and then the second condition. If we swap them, then things 
       will go wrong, cuz when you have even nodes, the slow runner will hit 
       the middle while fast runner hit the NULL. At this time, when you check 
       fast->next!=NULL, "Segmentation fault". */
 
    while(fast!=NULL&&fast->next!=NULL) 
    {
    	push(s, slow->val);
    	slow=slow->next;
    	fast=fast->next->next;    
    }

    /* for odd nodes, we need to skip the middle one; cannot use 
       fast->next==NULL, cuz if it has even node, fast==NULL, then things
       will go wrong */
    if(fast!=NULL)  
  
        slow=slow->next;
    
    while(s->size!=0)
    {
    	if(top(s)!=slow->val)
    	{
    		printf("Not palindrome!\n");
    		return;
    	}
    	else
    	{
    		pop(s);
    		slow=slow->next;
    	}
    }
    printf("palindrome!\n");
}

void freeList(struct Node *head)
{
    struct Node *cur;
    while(head!=NULL)
    {
        cur=head;
        head=head->next;
        free(cur);
    }
}


void main()
{
	char a[]="he3ah";
	struct Node *head;
	head=create(a);
	palindrome2(head);
	freeList(head);
}
