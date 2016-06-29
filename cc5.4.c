/*
cc5.4: Explain what the following code does: ((n&(n-1))==0).

  For binary representaion of n and n-1, in order to let the 
n&(n-1)==0 which means that n and n-1 is differen in every bit.
Thus, n is a power of 2 or n is 0.
*/

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n=1;
	if((n&(n-1))==0)
		printf("Y\n");
	else
		printf("N\n");
}