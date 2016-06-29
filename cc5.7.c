/*
cc5.7: An array A contains all the integers from 0 through n, except for one number which is missing. In this 
       problem, we cannot access an entire integer in A with a single operation. The elements of A are represented 
       in binary, and the only operation we can use to access them is "fetch the jth bit A[i]," which takes 
       contant time. Write code to find the missing integer. Can you do it in O(n) time?
IDEA: chech cc150 5th edition P261~P264!!
*/

#include <stdio.h>
 
int fetch(int A[], int i, int j)
{
	return (A[i]&(1<<j))>0? 1:0;
}

/* Time: O(n) cuz first time we check n/2 then n/4, n/8, .....*/
int findMissing(int A[], int n, int j)
{
	if(n==0)
		return 0;
	int ones[n], zeros[n];   //cannot initialize variable-sized object (e.g., ones[n]={0};)
	int size1=0, size0=0;
	int i;
	for(i=0; i<n; i++)
	{
		if(fetch(A, i, j))
		{
			ones[size1]=A[i];
			size1++;
		}
			
		else
	   {
			zeros[size0]=A[i];
			size0++;
		};
	}
	if(size0>size1)
		return (findMissing(ones, size1, j+1)<<1)|1;
	else
		return (findMissing(zeros, size0, j+1)<<1)|0;
}



void main()
{
	int A[5]={1, 2, 3, 4, 5};
	printf("Missing number is: %d\n", findMissing(A, 5, 0));
}










