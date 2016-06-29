/*
cc9.8: Given an infinite number of quarters (25 cents), dimes (10 cents), nickels
       (5 cents) and pennies (1 cent), write code to calculate the number of ways
       of representing n cents.

IDEA:  This is differen from cc9.1, cuz in cc9.1, (1, 4) is different from (4, 1)
       while in cc9.8, (1, 5) is the same as (5, 1). Thus, we cannot use the same
       solution as before. See Page 362-363!!

*/


#include <stdio.h>

#define N 4
int makeChange(int n)
{
	int denoms[N]={25, 10, 5, 1};
	int map[n+1][N];
//cannot use map[n+1][N]={0}, cuz variable-sized object may not be initialized.
	int i, j;
	for(i=0; i<n+1; i++)
	{
		for(j=0; j<N; j++)
			map[i][j]=0;
	}
	return make_change(n, denoms, 0, map);
}

int make_change(int amount, int denoms[], int index, int map[][N])
{
	if(map[amount][index]>0)
		return map[amount][index];
	if(index>=N-1)
		return 1;
	int denomsAmount=denoms[index];
	int ways=0;
	int i;
	for(i=0; i*denomsAmount<=amount; i++)
	{
		int amountRemaining=amount-i*denomsAmount;
		ways+=make_change(amountRemaining, denoms, index+1, map);
	}
	map[amount][index]=ways;
	return ways;
}


void main()
{
	printf("%d\n", makeChange(11));
}
