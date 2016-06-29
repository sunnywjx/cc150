/* 
cc3.2: How would you design a stack which, in addition to push and pop, has
       a function min which returns the minimum element? Push, pop and min
       should all operate in O(1) time.


思路：1. use a min array to keep track of the min value for all elements 
        beneath the current element. 
     2. use a min stack to store the min value, if the push element is 
        smaller than or equal to the top of the stack, we push the value 
        into the min stack; if the pop is equal to the top of the min 
        stack, we pop the value from the min stack. (比思路1省空间)

(1)   
    array  stack
    +---+  +---+
    |   |  |   |     capacity=4;
    +---+  +---+     size=0;
    | 3 |  | 3 |     
    +---+  +---+     push(5); size=1; min=5;          
    | 5 |  | 6 |     push(6); size=2; min=5;
    +---+  +---+     push(3); size=3; min=3;   
    | 5 |  | 5 |     pop();   size=2; min=5;
    +---+  +---+


(2)

  minStack stack
    +---+  +---+
    |   |  |   |     capacity=4;
    +---+  +---+     size=0;
    |   |  | 3 |     
    +---+  +---+     push(5); size=1; push(min)=5;          
    | 3 |  | 6 |     push(6); size=2; 
    +---+  +---+     push(3); size=3; push(min)=3;   
    | 5 |  | 5 |     pop();   size=2; pop(min);
    +---+  +---+

*/


#include <stdio.h>
#include <stdlib.h>

#define N 4

/*
struct Stack
{
	int capacity;
	int size;
	int *element;
	int *min;
};

struct Stack *initial()
{
	struct Stack *s;
	s=(struct Stack *)malloc(sizeof(struct Stack));
	s->element=(int *)malloc(sizeof(int)*N);
	s->min=(int *)malloc(sizeof(int)*N);
	s->capacity=N;
    s->size=0;
    return s;
}

void push(struct Stack *s, int x)
{
	if(s->size==s->capacity)
        {
                printf("No more room for push!\n");
                return;
        }
        if(s->size==0)
		s->min[s->size]=x;
	else if(x>s->min[s->size-1])
		s->min[s->size]=s->min[s->size-1];
	else
		s->min[s->size]=x;
	s->element[s->size]=x;
	s->size++;
}

void pop(struct Stack *s)
{
	if(s->size==0)
            printf("No more element to pop!\n");
        else
            s->size--;
}

int minstack(struct Stack *s)
{
	if(s->size==0)
            return -1;
        else
            return s->min[s->size-1];
}

int top(struct Stack *s)
{
	return s->element[s->size-1];
}



void main()
{
	struct Stack *s;
    s=initial();
	push(s, 5);
	printf("%d\n", top(s));
	push(s, 6);
	printf("%d\n", top(s));
	push(s, 3);
	printf("%d\n", top(s));
	push(s, 7);
	printf("%d\n\n", top(s));

	printf("%d\n", minstack(s));
	pop(s);
	printf("%d\n", minstack(s));
	pop(s);
	printf("%d\n", minstack(s));
	pop(s);
	printf("%d\n", minstack(s));
    pop(s);
	//printf("%d\n", minstack(s));
        //pop(s);
    
    free(s->element);
    free(s->min);
    free(s);
}
*/


/* -------------------------------------------------- */


struct Stack 
{
    int capacity;
    int size;
    int *element;
};

struct Stack *initial()
{
    struct Stack *s;
    s=(struct Stack *)malloc(sizeof(struct Stack));
    s->element=(int *)malloc(sizeof(int)*N);
    s->capacity=N;
    s->size=0;
    return s;
}


void push(struct Stack *s, int x)
{
    s->element[s->size]=x;
    s->size++;
}

void pop(struct Stack *s)
{
    s->size--;
}

int top(struct Stack *s)
{
    if(s->size==0)
        return -1;
    else
        return s->element[s->size-1];
}

void stackPush(struct Stack *s, struct Stack *minS, int x)
{
    if(s->size==s->capacity)
    {
        printf("No more room to push!\n");
        return;
    }

    if(s->size==0||x<=top(minS))
    {
        push(s, x);
        push(minS, x);
    }
    else 
    {
        push(s, x);
    }
    

}

void stackPop(struct Stack *s, struct Stack *minS)
{
    if(s->size==0)
    {
        printf("No element to pop!\n");
        return;
    }
    if(top(s)==top(minS))
    {
        pop(s);
        pop(minS);
    }
    else
    {
        pop(s);
    }
}


void main()
{
    struct Stack *s, *minS;
    s=initial();
    minS=initial();

    stackPush(s, minS, 5);
    printf("element= %d, min= %d\n", top(s), top(minS));

    stackPush(s, minS, 3);
    printf("element= %d, min= %d\n", top(s), top(minS));

    stackPush(s, minS, 6);
    printf("element= %d, min= %d\n", top(s), top(minS));

    stackPush(s, minS, 3);
    printf("element= %d, min= %d\n\n", top(s), top(minS));



    stackPop(s, minS);
    printf("element= %d, min= %d\n", top(s), top(minS));

    stackPop(s, minS);
    printf("element= %d, min= %d\n", top(s), top(minS));

    stackPop(s, minS);
    printf("element= %d, min= %d\n", top(s), top(minS));

    stackPop(s, minS);
    printf("element= %d, min= %d\n\n", top(s), top(minS));

    //stackPop(s, minS);

    
    free(s->element);
    free(s);
    
    free(minS->element);
    free(minS);

}






