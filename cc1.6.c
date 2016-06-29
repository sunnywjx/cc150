/*
cc1.6: Given an image represented by an NxN matrix, where each pixel in the
       image is 4 bytes, write a method to rotate the image by 90 degrees. Can
       you do this in place?

要求：1. do it in place.
     2. assume clockwise.

思路：一层层翻转，每层一个个翻转。


  In place: Algorithm that uses a small constant ( O(1) ) amount of extra space in
addition to the original input.

*/

#include <stdio.h>
#include <string.h>

#define N 5

/* Time:O(n^2), Extra Space:O(1) */
//The best time complexity is O(n^2) cuz it must touch n^2 elements.

void rotate(int a[][N])
{
	int i, top;
	int layer;
	int last, offset;
	for(layer=0; layer<N/2; layer++) 
	{
		last=N-layer-1;		
		for (i=layer; i<last; i++) 
		{   
			offset=N-1-i;
			top=a[layer][i];
		    a[layer][i]=a[offset][layer];
		    a[offset][layer]=a[last][offset];
		    a[last][offset]=a[i][last];
		    a[i][last]=top;
		}
	}
}



void main()
{
	int a[N][N]={
		            {11,12,13,14,15},
	                {21,22,23,24,25},
	                {31,32,33,34,35},
	                {41,42,43,44,45},
	                {51,52,53,54,55}
	            };
	rotate(a);
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}

}







