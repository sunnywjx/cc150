/*
cc3.1: Describe how you could use a single array to implement three stacks.

思路：1. use fixed size for each stack in the array, create a structure which
        is similar to single stack except that it contains 3 size for 3 
        stacks, and the total array is divided by 3.
     2. use flexible size of each stack(too complex!!!).
*/


#include <stdio.h>
#include <stdlib.h>

#define N 300
#define capacity N/3

/* cannot initial any value in the struct, cuz structure is a data type. You 
   don't give values to a data type. You give values to instances/objects 
   of data types. Thus, we need to create an instance in a function (main or 
   not main) to assign the values. */

struct ThreeStack
{
	int *array;
	int size[3];
};


struct ThreeStack *initial()
{
	struct ThreeStack *s;
	s=(struct ThreeStack *)malloc(sizeof(struct ThreeStack));
	s->array=(int *)malloc(sizeof(int)*N);
	s->size[0]=0;
	s->size[1]=0;
	s->size[2]=0;
	return s;
}

void push(struct ThreeStack *s, int stackNum, int x)
{
	if(s->size[stackNum]==capacity)
	{
		printf("Stack %d is full!\n", stackNum);
		return;
	}
	s->array[stackNum*capacity+s->size[stackNum]]=x;
	s->size[stackNum]++;
}

void pop(struct ThreeStack *s, int stackNum)
{
	if(s->size[stackNum]==0)
	{
		printf("Stack %d is empty!\n", stackNum);
		return;
	}
	s->size[stackNum]--;
}

int top(struct ThreeStack *s, int stackNum)
{
	if(s->size[stackNum]==0)
	{
		printf("Stack %d is empty!\n", stackNum);
		return -1;
	}
    else
	    return s->array[stackNum*capacity+s->size[stackNum]-1];
}

void main()
{
	struct ThreeStack *s;
	s=initial();
	push(s,0,1);
	printf("%d\n",top(s, 0));
	push(s,0,2);
	printf("%d\n",top(s, 0));
	push(s,0,3);
	printf("%d\n\n",top(s, 0));

	push(s,1,4);
	printf("%d\n",top(s, 1));
	push(s,1,5);
	printf("%d\n",top(s, 1));
	push(s,1,6);
	printf("%d\n",top(s, 1));
	push(s,1,7);
	printf("%d\n\n",top(s, 1));

	push(s,2,8);
	printf("%d\n",top(s, 2));
	push(s,2,9);
    printf("%d\n\n",top(s, 2));

    pop(s,0);
    printf("%d\n",top(s, 0));
    pop(s,0);
    printf("%d\n",top(s, 0));
    pop(s,0);
    printf("%d\n",top(s, 0));
    pop(s,0);

    free(s);
    free(s->array);
}
