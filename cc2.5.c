/*
cc2.5: You have two numbers represented by a linked list, where each node
       contains a single digit. The digits are stored in reverse order, such
       that the 1's digits is at the head of the list. Write a function that
       adds the two numbers and returns the sum as a linked list.
Input:  (7->1->6)+(5->9->2). That is, 617+295.
Output: 2->1->9. That is, 912.

FOLLOW UP
    Suppose the digits are stored in the forward order. 
Input:  (6->1->7)+(2->9->5). That is, 617+295.
Output: 9->1->2. That is, 912.

思路：1. 使用依次乘十得到十进制数字，使得链表变成两个数字，数字相加后再使用mod变成链表。
     2. 扫描链表，从低位开始，对应的两个node的值依次相加，把进位存在carry中，与下一对的
        值相加。
     3. FOLLOW UP：先reverse再相加，再reverse。
     
Pass by value V.S. Pass by reference
1. Pass by value means that you are making a copy of the actual parameter's
   value that is passed in. Use pass by value when you are only "using" the 
   parameter for some computation, not changing it for the client program. 
2. Pass by reference (also called pass by address), a copy of the address
   of the actual parameter is stored. Use pass by reference when you are
   changing the parameter passed in by the client program. 


void swapThemByVal(int a, int b) 
{
    int temp = a;
    a = b;
    b = temp;
}
swapThemByVal(i, j);

  First, we show the memory picture for swapThemByVal. The activation record
holds the memory for the two parameters, a and b, and the local variable,
temp. A copy of the values from main, in the contents of i and j, are copied.
All the manipulation is done in the activation record.
                       +-------------+                +-------------+  
        swapThemByVal: |+--+         | swapThemByVal: |+--+         |  
        (at start)     ||..| temp    | (after         ||10| temp    |  
main:                  |+--+         |  assignments)  |+--+         |  
  +----+               |+--+         |                |+--+         |  
i | 10 |               ||10| a       |                ||20| a       |  
  +----+               |+--+         |                |+--+         |  
  +----+               |+--+         |                |+--+         |  
j | 20 |               ||20| b       |                ||10| b       |  
  +----+               |+--+         |                |+--+         |  
                       +-------------+                +-------------+  
  The contents of memory of i and j don't change. The contents of memory in
the function's activation record changes, but when the function terminates, 
the memory is released and the changes are lost. 



void swapThemByRef(int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;
}
swapThemByRef(i, j);

  Contrast this with passing by reference. The addresses of i and j are
passed (noted by the arrows) by reference. The compiler knows they are
references so when the parameters are referred to in the function, the 
compiler dereferences a and b automatically, so i and j of main's memory
are changed.
                       +-------------+
        swapThemByRef: |+--+         |
                       ||..| temp    |
main:                  |+--+         |
  +----+               |+--+         |
i | 10 | <-------------||--| a       |
  +----+               |+--+         |
  +----+               |+--+         |
j | 20 | <-------------||--| b       |
  +----+               |+--+         |
                       +-------------+
After the assignments:
                       +-------------+
        swapThemByRef: |+--+         |
                       ||10| temp    |
main:                  |+--+         |
  +----+               |+--+         |
i | 20 | <-------------||--| a       |
  +----+               |+--+         |
  +----+               |+--+         |
j | 10 | <-------------||--| b       |
  +----+               |+--+         |
                       +-------------+
  This is the essence of pass by value vs. pass by reference. It doesn't 
matter if the parameters are primitive types, arrays, or objects, either a 
copy is made or an address is stored.  
  In C, pass by reference is simulated by passing the address of a variable
(a pointer) and dereferencing that address within the function to read or 
write the actual variable. This will be referred to as "C style pass by 
reference."
  e.g.,  void f(int *j) 
         {
             (*j)++;
         } 
         void main()
         {
             int i=20;
             f(&i);
         }



*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int val;
	struct Node *next;
}Node;

Node *create1(int a[], int n) /* 头插法：reverse order, no head node */
{
	Node *top, *s;
	int i;
	top=NULL;
	for(i=0; i<n; i++)
	{
		s=(Node *)malloc(sizeof(Node));
		if(s==NULL)
			return NULL;
		s->val=a[i];
		s->next=top;
		top=s;
	}
	return top;
}

Node *create2(int a[], int n) /* 尾插法：forward order, no head node */
{
	Node *head, *tail, *s;
	int i;
	head=NULL;
	tail=NULL;
	for(i=0; i<n; i++)
	{
		s=(Node *)malloc(sizeof(Node));
		if(s==NULL)
			return NULL;
		s->val=a[i];
    s->next=NULL;
    if(head==NULL)
    { 
      head=s;
      tail=s;
    }
    else
		{
		  tail->next=s;
		  tail=s;
    }
	}
	return head;
}

Node *reverse(Node *head)
{
	Node *p1, *p2;
	
	p1=NULL;
	p2=head->next;
	while(p2!=NULL)
	{
		head->next=p1;
		p1=head;
		head=p2;
		p2=p2->next;
	}
  head->next=p1;
	return head;
}

/* Time:O(n), Extra Space:O(n) */
Node *sumList1(Node *x, Node *y)
{
    Node *p, *q, *head=NULL, *s;
    int a=0, b=0, a_shi=1, b_shi=1, sum;
    p=x;
    q=y;
    while(p!=NULL)
    {
        a=a+(p->val)*a_shi;
        a_shi*=10;
        p=p->next;
    }
    while(q!=NULL)
    {
        b=b+(q->val)*b_shi;
        b_shi*=10;
        q=q->next;
    }
    sum=a+b;
    while(sum!=0)
    {
        s=(Node *)malloc(sizeof(Node));
        if(s==NULL)
	    return NULL;        
        s->val=sum%10;
        s->next=head;
        head=s;
        sum=(sum-sum%10)/10;
    }
    return reverse(head);
}


void choosecarry(Node *s, int p, int q, int *carry)
{
   
    if(p+q+*carry>9)
    {
         s->val=p+q-10+*carry;
         *carry=1; 
    }
    else
    {
         s->val=p+q+*carry;
         *carry=0;
    }
     
}

/* Time:O(n), Extra Space:O(n) */
Node *sumList2(Node *x, Node *y)
{
    Node *p, *q, *head=NULL, *s;
    int carry=0;
    p=x;
    q=y;
    while(p!=NULL&&q!=NULL)
    {
        s=(Node *)malloc(sizeof(Node));
        if(s==NULL)
	    return NULL; 
        choosecarry(s, p->val, q->val, &carry);
        //printf("%d\n",carry);
        //printf("*%d*\n",s->val);
        s->next=head;
        head=s;
        p=p->next;
        q=q->next;   
    }
    while(p!=NULL)
    {
        s=(Node *)malloc(sizeof(Node));
        if(s==NULL)
	    return NULL;
        choosecarry(s, p->val, 0, &carry);
        s->next=head;
        head=s;
        p=p->next;
    }
    while(q!=NULL)
    {
        s=(Node *)malloc(sizeof(Node));
        if(s==NULL)
	    return NULL;
        choosecarry(s, 0, q->val, &carry);
        s->next=head;
        head=s;
        q=q->next;
    }
    if(carry==1)
    {
        s=(Node *)malloc(sizeof(Node));
        if(s==NULL)
	    return NULL; 
        s->val=carry;
        s->next=head;
        head=s;
    }
    return head;
}


void print(Node *head)
{
    Node *x;
    x=head;
    while(x!=NULL)
    {
      printf("%d ", x->val);
	    x=x->next;
    }
    printf("\n");
}


void freeList(Node *head)
{
    Node *cur;
    while(head!=NULL)
    {
        cur=head;
        head=head->next;
        free(cur);
    }
}

void main()
{
  int a[]={9,6,1,7};
  int b[]={3,9,5};
    //swap(3,4);
  int choose;
	Node *x, *y, *sum, *xrev;
	printf("Choose your order (1: reverse order, 2: forward order):");
	scanf("%d", &choose);
	switch(choose)
	{
		case 1:
		    x=create1(a, 4);
	      y=create1(b, 3);
	      sum=sumList1(x, y);
        print(x);
        print(y);
        print(sum);
		    break;
		case 2:
		    x=create2(a, 4);
	      y=create2(b, 3);
        print(x);
        print(y);
        x=reverse(x);
        y=reverse(y);
        sum=sumList2(x, y);
        print(sum);
		    break;
	}
	
	freeList(x);
  freeList(y);
  freeList(sum);
}
