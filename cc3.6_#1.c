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


3.  If we use pointer for type and timestamp, then we need to malloc not only q but
also q->type and q->timestamp!!

e.g.,
      +---------+
      |   size  |
  q-->+---------+
      | capacity|        
      +---------+
      |   from  |
      +---------+
      |   rear  |
      +---------+     +-----+           +-----+
      |   type  |---->|     |     +---->|     |
      +---------+     +-----+     |     +-----+
      |timestamp|     |     |     |     |     |
      +---------+     +-----+     |     +-----+
           |          |     |     |     |     |
           |          +-----+     |     +-----+
           |          |     |     |     |     |
           |          +-----+     |     +-----+
           |          |     |     |     |     |
           |          +-----+     |     +-----+
           |                      |
           +----------------------+

4.  char a[10];
    a=(char *)malloc(sizeof(char)*10);
    Wrong!!Cannot convert a[10] into a pointer!!

    char a[];
    a=(char *)malloc(sizeof(char)*10);
    Wrong!!Cannot convert a[] into a pointer!!

    char *a;
    a=(char *)malloc(sizeof(char)*10);
    Right!!Allocate storge for pointer pointing to.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
   

#define N 5
#define TRUE 1
#define FALSE 0

char animal[10]; //global variable
char error[50];
/*
    When a local variable is defined, it is not initialized by the system, you must 
    initialize it yourself. Global variables are initialized automatically by the 
    system when you define them.
    e.g., int -- 0
          float --0
          double -- 0
          char -- '\0'
          pointer -- NULL
    A program can have same name for local and global variables, but in the function
    where you declare the local variables, local variables take precedence over global
    variables.
    e.g.,
          int g=20;
          void main()
          {
	          int g=10;
	          printf("%d\n", g);  // outcome will be 10.
          }
*/
struct queue
{
    int size;
    int capacity;
    int from;
    int rear;
    
	char name[N][10];
	//int type[N];  //1:cat, 0:dog
	int timestamp[N];
	/* if we define the num already, no need malloc!! malloc only use for pointer
	   when we do not know the specific num!! */
	
};


struct queue *create()
{
	struct queue *q;
	q=(struct queue *)malloc(sizeof(struct queue));
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


void push(struct queue *q, char name[], int time)
{
	//int i;
	q->size++;
	q->rear++;
	/* for(i=0; i<strlen(name); i++)
	       q->name[q->rear][i]=name[i];
	   q->name[q->rear][i]='\0'; (solution 1) */
	strcpy(q->name[q->rear], name); /* (solution 2) */
	q->timestamp[q->rear]=time;
	//q->type[q->rear]=type;
}

void pop(struct queue *q)
{
	q->size--;
	q->from++;
}

void enqueue(struct queue *cat, struct queue *dog, char name[], int time, int type)
{
	if(type==1)  //cat
		push(cat, name, time);
	else         //dog
		push(dog, name, time);
}

char *dequeueCat(struct queue *cat)
{
	if(isEmpty(cat))
		return strcpy(error, "There is no more cat!");
	else
	{
		strcpy(animal, cat->name[cat->from]);
	    pop(cat);
	    return animal;
	}
	
}



char *dequeueDog(struct queue *dog)
{
	if(isEmpty(dog))
		return strcpy(error, "There is no more dog!");
	else
	{
		strcpy(animal, dog->name[dog->from]);
	    pop(dog);
	    return animal;
	}
}

char *dequeueAny(struct queue *cat, struct queue *dog)
{
	if(isEmpty(cat)&&isEmpty(dog))
		return strcpy(error, "There is no more cat and dog!");
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
  
	enqueue(cat, dog, "Alpha", 0, 1); //cat A
	//enqueue(cat, dog, "Bily", 1, 1); //cat B
	//enqueue(cat, dog, "Casy", 2, 1); //cat C
	//enqueue(cat, dog, "David", 3, 1); //cat D

	//enqueue(cat, dog, "Ella", 4, 0); //dog A
	//enqueue(cat, dog, "Fulno", 5, 0); //dog B
	//enqueue(cat, dog, "Gallio", 6, 0); //dog C
	//enqueue(cat, dog, "Hellen", 7, 0); //dog D

	
	
    printf("%s\n", dequeueCat(cat));
    //printf("%s\n", dequeueCat(cat));
    //printf("%s\n", dequeueCat(cat));
    //printf("%s\n", dequeueCat(cat));
    //printf("%s\n", dequeueCat(cat));

    printf("%s\n", dequeueDog(dog));
    //printf("%s\n", dequeueDog(dog));
    //printf("%s\n", dequeueDog(dog));
    //printf("%s\n", dequeueDog(dog));
    //printf("%s\n", dequeueDog(dog));

    printf("%s\n", dequeueAny(cat, dog));

   

    free(cat);
    free(dog);



}
