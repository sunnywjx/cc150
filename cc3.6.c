/*
cc3.6: An animal shelter, which holds only dogs and cats, operates on a strictly 
       "first in first out" basis. People must adopt either the "oldest"(based on 
       the arrival time) of all animals at the shelter, or they can select whether
       they would prefer a dog or a cat (and will receive the oldest animal of 
       that type). They cannot select which specific animal they would like. 
       Create the data structures to maintain this system and implement operations 
       such as enqueue, dequeueAny, dequeueDog, dequeueCat. You may use the 
       built-in LinkedList data structure.

IDEA: Create two queues for dog and cat. For dequeueAny, we need to first compare
      the time of both cat and dog, then dequeue the older one.


1.  In a function in C, "return 0" simply means a function returns 0 to its caller. 
"return" can return any expression in C, although the expression has to be a type 
that is compatible with the return type of the function.
    In main() (or similar top-level functions in other programming environments), 
"return" has the added purpose of returning a value to the invocation environment, 
so it will be the exit value of the program itself.
    On Linux, main's return value should be an 8 bit integer value, usually 0 for 
"success" and 1 for "something bad". 


2.  Printf is the same thing as fprintf(stdout, it's just a matter of style. 
Stdout goes to standard output, stderr standard error. Both stdout and stderr are 
both redirected to the console (the screen) by default. But you can change that, 
by redirecting one or both to one or two files, or piping them to different 
application's input, or whatever. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5
#define TRUE 1
#define FALSE 0


struct queue
{
    int size;
    int capacity;
    int from;
    int rear;
    
	char *name;
	int *type;  //1:cat, 0:dog
	int *timestamp;
};

struct queue *create()
{
	struct queue *q;
	q=(struct queue *)malloc(sizeof(struct queue));
	q->name=(char *)malloc(sizeof(char)*N);
	q->timestamp=(int *)malloc(sizeof(int)*N);
	q->type=(int *)malloc(sizeof(int)*N);
	q->capacity=N;
	q->size=0;
	q->from=0;
	q->rear=-1;
	return q;
}

int isEmpty(struct queue *q)
{
	if(q->size==0)
		return 1;
	else
		return 0;
}


void push(struct queue *q, char name, int time, int type)
{
	q->size++;
	q->rear++;
	q->name[q->rear]=name;
	q->timestamp[q->rear]=time;
	q->type[q->rear]=type;
}

void pop(struct queue *q)
{
	q->size--;
	q->from++;
}

void enqueue(struct queue *cat, struct queue *dog, char name, int time, int type)
{
	if(type==1)  //cat
		push(cat, name, time, type);
	else         //dog
		push(dog, name, time, type);
}

char dequeueCat(struct queue *cat)
{
	char name;
	if(isEmpty(cat))
	{
		fprintf(stderr, "There is no more cat!\n");
		return '\0';
	}
	else
	{
		name=cat->name[cat->from];
	    pop(cat);
	    return name;
	}
	
}

char dequeueDog(struct queue *dog)
{
	char name;
	if(isEmpty(dog))
	{
		fprintf(stderr, "There is no more dog!\n");
		return '\0';
	}
	else
	{
		name=dog->name[dog->from];
	    pop(dog);
	    return name;
	}
}

char dequeueAny(struct queue *cat, struct queue *dog)
{
	if(isEmpty(cat)&&isEmpty(dog))
	{
		fprintf(stderr, "There is no more cat and dog!\n");
		return '\0';
	}
	if(isEmpty(cat))
		return dequeueDog(dog);
	else if(isEmpty(dog))
		return dequeueCat(cat);
	else
		return cat->timestamp[cat->from]<dog->timestamp[dog->from]? dequeueCat(cat):dequeueDog(dog);

}

void main()
{
	struct queue *cat, *dog;
    cat=create();
    dog=create();
	enqueue(cat, dog, 'A', 0, 1); //cat A
	//enqueue(cat, dog, 'B', 1, 1); //cat B
	//enqueue(cat, dog, 'C', 2, 1); //cat C
	//enqueue(cat, dog, 'D', 3, 1); //cat D
	enqueue(cat, dog, 'E', 4, 0); //dog A
	//enqueue(cat, dog, 'F', 5, 0); //dog B
	//enqueue(cat, dog, 'G', 6, 0); //dog C
	//enqueue(cat, dog, 'H', 7, 0); //dog D
    printf("%c\n", dequeueCat(cat));
    printf("%c\n", dequeueCat(cat));
    printf("%c\n", dequeueDog(dog));
    printf("%c\n", dequeueDog(dog));
    printf("%c\n", dequeueAny(cat, dog));

    free(cat);
    free(cat->name);
    free(cat->timestamp);
    free(cat->type);
    free(dog);
    free(dog->name);
    free(dog->timestamp);
    free(dog->type);



}
