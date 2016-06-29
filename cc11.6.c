/*
cc11.6: Given an MxN matrix in which each row and each column is sorted in ascending order, write a method to find 
        an element.

IDEA:   1. If the start of a column is greater than x, col--;
        2. If the end of a row is smaller than x, row++.

*/


#include <stdio.h>

#define TRUE 1
#define FALSE 0        
#define M 4
#define N 4

int findElem(int matrix[][N], int elem)
{
	int row=0;
	int col=N-1;
	while(row<M&&col>=0)
	{
		if(matrix[row][col]==elem)
			return TRUE;
		else if(matrix[row][col]>elem)
			col--;
		else
			row++;
	}
	return FALSE;
}


void main()
{
	int matrix[M][N]={
		               {15, 20, 40, 85},
		               {20, 35, 80, 95},
		               {30, 55, 95, 105},
		               {40, 80, 100, 120}
	                 };
	printf("%d\n", findElem(matrix, 55));
}