/*
cc3.4: In the classic problem of the Towers of Hanoi, you have 3 rods and N disks 
       of different sizes which can slide onto any tower. The puzzle starts with 
       disks sorted in ascending order of size from top to bottom(e.g., each disk 
       sits on top of an even larger one). You have the following constraints:
           a. Only one disk can be moved at a time.
           b. A disk is slid off the top of one rod onto the next rod.
           c. A disk can only be placed on the top of a larger disk.
       write a program to move the disks from the first rod to the last using 
       Stacks.

Recursion:

1. move n-1 discs from A to B. This leaves disc n alone on rod A.
2. move disc n from A to C.
3. move n-1 discs from B to C. So they sit on disc n. 

  The above is a recursive algorithm, to carry out steps 1 and 3, apply the same 
algorithm again for n−1. The entire procedure is a finite number of moves, since 
at some point the algorithm will be required for n = 1, moving a single disc from 
rod A to rod C, is trivial.
  Since n discs take Tn=2*Tn-1+1 moves, the total moves required is 2^n-1.
e.g.,
      T3=2*T2+1
      T2=2*T1+1
      T1=1
      ==>T3=7=2^3-1


*/




#include <stdio.h>
#include <stdlib.h>

#define N 4

struct Tower
{
	int capacity;
	int size;
	int *plate;
	char name;
};

struct Tower *create(char name)
{
	struct Tower *T;
	T=(struct Tower *)malloc(sizeof(struct Tower));
	T->plate=(int *)malloc(sizeof(int)*N);
	T->capacity=N;
	T->size=0;
	T->name=name;
	return T;
}

void push(struct Tower *T, int x)
{
	T->plate[T->size]=x;
	T->size++;
}

void pop(struct Tower *T)
{
	T->size--;
}

int top(struct Tower *T)
{
	return T->plate[T->size-1];
}

void move(struct Tower *from, struct Tower *to)
{
	int x;
	x=top(from);
	pop(from);
	push(to, x);
	printf("move %d from %c to %c.\n", x, from->name, to->name);
}

void Hanoi(int n, struct Tower *from, struct Tower *buf, struct Tower *to)
{
	if(n==1)
		move(from, to);
	else
	{
		Hanoi(n-1, from, to, buf);
		move(from, to);
		Hanoi(n-1, buf, from, to);
	}
}




void main()
{
	struct Tower *T1, *T2, *T3;
	int i;
	T1=create('A');
	T2=create('B');
	T3=create('C');
	for(i=N; i>0; i--)
	{
		push(T1, i);
	}
	Hanoi(N, T1, T2, T3);
	free(T1);
	free(T2);
	free(T3);
	free(T1->plate);
	free(T2->plate);
	free(T3->plate);
}


/*
void Hanoi(int n, char from, char buf, char to)
{
	if(n==1)
		printf("move 1 from %c to %c.\n", from, to);
	else
	{
		Hanoi(n-1, from, to, buf);
		printf("move %d from %c to %c.\n", n, from, to);
		Hanoi(n-1, buf, from, to);
	}
}

void main()
{
	Hanoi(4, 'A', 'B', 'C');
}
*/
