/*
cc3.3: Imagine a (literal) stack of plates. If the stack gets too high, it 
       might topple. Therefore, in real life, we would likely start a new 
       stack when the previous stack exceeds some threshold. Implement a 
       data structure SetOfStacks that mimics this. SetOfStacks should be 
       composed of several stacks and should create a new stack once the 
       previous one exceeds capacity. SetOfStacks.push() and SetOfStacks
       .pop() should behave identically to a single stack (that is, pop() 
       should return the same values as it would if there were just a single 
       stack).

FOLLOW UP
  Implement a function popAt(int index) which performs a pop operation on a 
special sub stack.

思路：(不能多次对同一个pointer进行malloc，pointer只会指向最新的空间，之前的空间将遗失！！)
     使用一个num来表示当前有元素的第n个stack，当stack满了，则num++;当stack空了，则num--。
FOLLOW UP: 当使用popAt或是pop的时候，需要注意的是，有可能之前的一个或多个stack已经被popAt
           清空了，所以再使用pop或popAt清空当前stack的时候，num不再是减一，而是减去多个空
           的stack；因此，此处需要用到while！！


*/


#include <stdio.h>
#include <stdlib.h>

#define N 20
#define cap 3   //every stack has the same capacity

struct Stack 
{
	int size;   //current number of elements in the stack
	int capacity;
	int *element;
};

struct SetOfStacks
{
	int num; /* ?th stack:0~99 */
	struct Stack *set;
};

struct SetOfStacks *create()
{
	struct SetOfStacks *ss;
    int i;
	ss=(struct SetOfStacks *)malloc(sizeof(struct SetOfStacks));
	ss->set=(struct Stack *)malloc(sizeof(struct Stack)*N);
    for(i=0; i<N; i++)
    {
	    ss->set[i].element=(int *)malloc(sizeof(int)*cap);
	    ss->set[i].capacity=cap;
	    ss->set[i].size=0;
    }
	ss->num=0;
	return ss;
}

void push(struct SetOfStacks *ss, int x)
{
    if(ss->num==N-1&&ss->set[ss->num].size==cap)
    {
        printf("The SetOfStack is full!\n");
        return;
    }
    if(ss->set[ss->num].size==cap)
    {
        ++ss->num;
    }
    ss->set[ss->num].element[ss->set[ss->num].size]=x;
    ss->set[ss->num].size++;    
}

void pop(struct SetOfStacks *ss)
{  
    /* It is possible that a previous stack is empty by using popAt() for
       cap times.Thus, we need to jump over the empty one. */  
    if(ss->num==0&&ss->set[ss->num].size==0)
    {
        printf("No element to pop!\n");
        return;
    }
    ss->set[ss->num].size--; 
    while(ss->set[ss->num].size==0&&ss->num>0)
    {
        ss->num--;
    }
}


void popAt(struct SetOfStacks *ss, int index)
{
    if(index<0)
        printf("The index is invalid!\n");
    if(index>ss->num)
    {
        printf("There is no element in the %dth stack!\n", index);
        printf("The last element is ");
        printf("%d, ", ss->set[ss->num].element[ss->set[ss->num].size-1]);
        printf("in the %dth stack!\n", ss->num);
    }
    
    if(index<ss->num)
    {
        if(ss->set[index].size==0)
        {
            printf("No element in this stack!\n");
            return;
        }
        ss->set[index].size--;
    }
    if(index==ss->num)
    {
        if(ss->set[index].size==0)
        {
            printf("No element in this stack!\n");
            return;
        }
        ss->set[index].size--;
        while(ss->set[ss->num].size==0&&ss->num>0)
           ss->num--;
    }
}

int top(struct SetOfStacks *ss)
{   
    return ss->set[ss->num].element[ss->set[ss->num].size-1];
}

void main()
{
	struct SetOfStacks *ss;
        int i;
	ss=create();

      
        push(ss, 0);
        printf("push= %d\n", top(ss));
        push(ss, 1);
        printf("push= %d\n", top(ss));
        push(ss, 2);
        printf("push= %d\n\n", top(ss));

        push(ss, 3);
        printf("push= %d\n", top(ss));
        push(ss, 4);
        printf("push= %d\n", top(ss));
        push(ss, 5);
        printf("push= %d\n\n", top(ss));
      

        push(ss, 6);
        printf("push= %d\n", top(ss));
        push(ss, 7);
        printf("push= %d\n", top(ss));
        push(ss, 8);
        printf("push= %d\n\n\n", top(ss));

        //pop(ss);
       // printf("top= %d\n", top(ss));
        //pop(ss);
        //printf("top= %d\n", top(ss));
        //pop(ss);
       // printf("top= %d\n", top(ss));

        //popAt(ss, 3);
        popAt(ss, 1);
        popAt(ss, 1);
        popAt(ss, 1);
        printf("top= %d\n", top(ss));
        pop(ss);
        pop(ss);
        printf("top= %d\n", top(ss));
        pop(ss);
        printf("top= %d\n", top(ss));
        popAt(ss,0);
 printf("%d\n", ss->set[ss->num].size);
        popAt(ss,0);
 printf("%d\n", ss->set[ss->num].size);
        popAt(ss,0);
 printf("%d\n", ss->set[ss->num].size);
   
        popAt(ss,0);
        
        
      
        for(i=0; i<N; i++)
	        free(ss->set[i].element);
        free(ss->set);
        free(ss);
       
}











