/*
cc3.5: Write a program to sort a stack such that the smallest items are on the top.
       You can use an additional temporary stack, but you may not copy the elements
       into any other data structure(such as an array). The stack supports the 
       following operations: push, pop, peek and isEmpty.

IDEA: 1. Use two stacks, one is the original, the other is the sorted. First, we push 
      one element from original to sorted. Then, every time we want to push a new 
      element into the sorted, we need to pop the top element of the original and 
      store it in a temp, then compare with the sorted's top, if temp is bigger than
      the sorted's top, we pop the sorted top and push into the original, then push 
      the temp into the sorted; otherwise, just push the temp into the sorted. This
      is similar to insertion sort(+2 stacks)!!
      2. Use three stacks, one is the original, one is the buffer, the other is the
      sorted. Every time we will go through the original to find the biggest element
      in the stack and store it in the sorted; we use buffer as temporary store for
      our search(+ 3 stacks)!!

*/


#include <stdio.h>
#include <stdlib.h>

#define N 5
#define TRUE 1
#define FALSE 0

struct stack
{
	int capacity;
	int size;
	int *element;
};

struct stack *create()
{
	struct stack *s;
	s=(struct stack *)malloc(sizeof(struct stack));
	s->element=(int *)malloc(sizeof(int)*N);
	s->capacity=N;
	s->size=0;
	return s;
}

void push(struct stack *s, int x)
{
	s->element[s->size]=x;
	s->size++;
}

void pop(struct stack *s)
{
	s->size--;
}

int peek(struct stack *s)
{
	return s->element[s->size-1];
}

int isEmpty(struct stack *s)
{
	if(s->size==0)
		return TRUE;
	else
		return FALSE;
}

/* Time: O(n^2), Extra Space: O(n) */
struct stack *sort1(struct stack *s)
{
	struct stack *new;
    new=create();
    int temp;
    while(!isEmpty(s))
    {
    	temp=peek(s);
    	pop(s);
    	while(!isEmpty(new)&&temp>peek(new))
    	{
    		push(s, peek(new));
    		pop(new);
    	}
    	push(new, temp);
    }
    return new;
}


struct stack *sort3(struct stack *s)
{
	struct stack *new;
    new=create();
    int temp;
    while(!isEmpty(s))
    {
    	if(new->size==0||peek(s)<=peek(new))
    	{
    		push(new, peek(s));
    		pop(s);
    	}
    	else
    	{
    		temp=peek(s);
    		pop(s);
    		while(new->size!=0&&peek(new)<temp)
    		{
    			push(s, peek(new));
    			pop(new);
    		}
    		push(new, temp);
    	}
    }
    return new;
}

/* Time:O(n^2), Extra Space:O(n) */
struct stack *sort2(struct stack *s)
{
	struct stack *new, *buf;
	int i, max;
	new=create();
	buf=create();
	while(!isEmpty(s))
	{
		max=peek(s);
		while(!isEmpty(s)) /* push from original to buf to find the max */
	    {
	    	if(peek(s)>max)
	    		max=peek(s);
	    	push(buf, peek(s));
	    	pop(s);
	    }
	    while(!isEmpty(buf)) /* push from buf to original or new */
	    {
	    	if(peek(buf)==max)
	    	{
	    		push(new, peek(buf));
	    		pop(buf);
	    	}
	    	else
	    	{
	    		push(s, peek(buf));
	    		pop(buf);
	    	}
	    }
	}
	
	free(buf->element);
	free(buf);
	return new;
}


void main()
{
	struct stack *s, *new;
	s=create();
	push(s, 8);
	push(s, 7);
	push(s, 5);
	push(s, 10);
	push(s, 10);
	new=sort3(s);
	while(!isEmpty(new))
	{
		printf("%d\n", peek(new));
		pop(new);
	}
	
	free(s->element);
	free(s);
	
	free(new->element);
	free(new);
}




