/*
cc11.1: You are given two sorted arrays, A and B, where A has a large enough buffer at the end to hold B. Write a
        method to merge B into A in sorted order. 

IDEA:   1. Insertion sort.
        2. From the last element, compare A and B, insert them in order.

*/

#include <stdio.h>


/* Time: O(MN) */
void mergeBtoA1(int A[], int B[], int M, int N)  // M: num of element in a[], N: num of elements in b[]
{
	int i, j;
	for(i=0; i<N; i++)
	{
		int current=B[i];
        j=M-1;
        while(j>=0&&A[j]>current)
        {
        	A[j+1]=A[j];
        	j--;
        }
        A[j+1]=current;
        M++;
	}
}

/* Time: O(M+N) */
void mergeBtoA2(int A[], int B[], int M, int N)
{
	int indexA=M-1;
	int indexB=N-1;
	int mergeAB=M+N-1;
	while(indexB>=0)
	{
		if(indexA>=0&&A[indexA]>B[indexB])
		{
			A[mergeAB]=A[indexA];
			indexA--;
		}
		else
		{
			A[mergeAB]=B[indexB];
            indexB--;
		}
		mergeAB--;
	}
}


void main()
{
	int a[5]={2, 4};
	int b[3]={1, 3, 5};
	mergeBtoA1(a, b, 2, 3);
	int i;
	for(i=0; i<5; i++)
		printf("%d ", a[i]);
	printf("\n");
}