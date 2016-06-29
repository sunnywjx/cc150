/*
cc9.1: A child is running up a staircase with n steps and can hop either 1 step, 
       2 steps or 3 steps at a time. Implement a method to count how many possible 
       ways the child can run up the stairs.

IDEA:  1. Top-Down.
       2. Bottom-Up.
*/



#include <stdio.h>

// Time: O(n)       
int countWays1(int n)
{
	int memo[n+1];
	int i;
	for(i=0; i<n+1; i++)
		memo[i]=-1;
	return countWays(n, memo);
}

int countWays(int n, int memo[])
{
	if(n<0)
		return 0;
	else if(n==0)
		return 1;
	else if(memo[n]>-1) //memo[n] already has the value stored.
		return memo[n];
	else
	{
		memo[n]=countWays(n-1, memo)+countWays(n-2, memo)+countWays(n-3,memo);
		return memo[n];
	}
}
// Time: O(n)
int countWays2(int n) 
{
	if(n<0) 
		return 0;
	int array[n+1];
	array[0]=1;
	array[1]=1;
	array[2]=2;
	int i;
	for(i=3; i<=n; i++)
	{
		array[i]=array[i-1]+array[i-2]+array[i-3];
	}
	return array[n];
}


void main()
{
	printf("Top-Down= %d\n", countWays1(5));
	printf("Bottom-Up= %d\n", countWays2(5));
}



