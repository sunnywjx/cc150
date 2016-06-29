/*
cc9.3: A magic index in an array A[0...n-1] is defined to be an index such that
       A[i]=i. Given a sorted array of distinct integers, write a method to find
       a magic index, if one exists, in array A.
       FOLLOW UP
       What if the values are not distinct?

IDEA:  1. Brute force--interate the whole array.
       2. Binary search--if A[middle]>middle, check left; else, check right.
       3. FOLLOW UP--similar to binary search except that we need to check both 
          right and left sides (with a little different!!) If A[middle]<middle,
          then for index A[middle] must on the left of middle; thus, we need to
          search the range from start to A[middle] and from middle+1 to end.If 
          A[middle]>middle, then for index A[middle] must on the right of middle; 
          thus, we need to search the range from start to middle-1 and from 
          A[middle] to end.

                A[middle]<=middle-1                 A[middle]>middle-1  
                A[middle]<middle+1                  A[middle]>=middle+1
       [start, A[middle]], [middle+1, end]    [start, middle-1], [A[middle], end]

       Thus, left = [start, min(A[middle], middle-1)];
             right = [max(A[middle], middle+1) ,end].

*/


#include <stdio.h>

#define MAX(a, b) ((a)>(b)? (a):(b))
#define MIN(a, b) ((a)<(b)? (a):(b))         
#define N 11

//Time: O(n)
int MagicIndex1(int A[])
{
	int i;
	for(i=0; i<N; i++)
	{
		if(A[i]==i)
			return i;
	}
	return -1;
}

//Time: O(logN)
int MagicIndex2(int A[])
{
	return MagicIndex(A, 0, N-1);
}

int MagicIndex(int A[], int start, int end)
{
	if(start>end)
		return -1;
	int middle=(start+end)/2;
	if(A[middle]==middle)
		return middle;
	else if(A[middle]>middle)
		return MagicIndex(A, start, middle-1);
	else
		return MagicIndex(A, middle+1, end);
}

//FOLLOW UP--Time: O()
int MagicIndex3(int A[])
{
	return MagicIndexFollowUp(A, 0, N-1);
}

int MagicIndexFollowUp(int A[], int start, int end)
{
	if(start>end)
		return -1;
	int middle=(start+end)/2;
	if(A[middle]==middle)
		return middle;

	int left=MagicIndexFollowUp(A, start, MIN(A[middle], middle-1));
	if(left>=0)
		return left;

    int right=MagicIndexFollowUp(A, MAX(A[middle], middle+1), end);
	if(right>=0)
		return right;
}



void main()
{
	int A[N]={-40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13};
	int B[N]={-1, 1, 3, 3, 5, 6, 7, 8, 9, 10, 10};
	printf("The magic index is %d\n", MagicIndex1(A));
	printf("The magic index is %d\n", MagicIndex2(A));
	printf("The magic index is %d\n", MagicIndex3(A));
}






