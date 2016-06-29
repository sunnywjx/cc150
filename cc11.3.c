/*
cc11.3: Given a sorted array of n integers that has been rotated an unknown number of times, write code to find an
        element in the array. You may assume that the array was originally sorted in increasing order.
        EXAMPLE
        Input: find 5 in {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14}
        Output: 8(the index of 5 in the array)
 
*/

#include <stdio.h>

#define N 7

int findX(int a[], int left, int right, int x)
{
	int mid=(left+right)/2;
	if(a[mid]==x)
		return mid;
	if(left>right)
		return -1;
	if(a[left]<a[mid]) //left is in order
	{
		if(x>=a[left]&&x<a[mid]) //x in left half
			return findX(a, left, mid-1, x);
		else
			return findX(a, mid+1, right, x);
	}
	else if(a[left]>a[mid])  //right is in order
	{
		if(x>a[mid]&&x<=a[right])
			return findX(a, mid+1, right, x);
		else
			return findX(a, left, mid-1, x);
	}else if(a[left]==a[mid]) 
	{
		if(a[mid]!=a[right]) // left half is all repeated, right half is different
			return findX(a, mid+1, right, x);
		else
		{
			int result=findX(a, left, mid-1, x);
			if(result==-1)
				return findX(a, mid+1, right, x);
			else 
				return result;
		}
	}
    return -1;

}

void main()
{
	int a[N]={3, 0, 1, 2, 3, 3, 3};
	printf("The index is %d\n", findX(a, 0, N-1, 3));
}