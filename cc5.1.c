/*
cc5.1: You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to 
       insert M into N such that M starts at bit j and ends at bit i. You can assume that the bits
       j through i have enough space to fit all of M. That is, if M=10011, you can assume that there
       are at least 5 bits between j and i. You would not, for example, have j=3 and i=2, because M
       could not fully fit between bit 3 and bit 2.


IDEA: Step1-- Clean the bits j through i in N;
      Step2-- Shift M so that it will line up with bits j through i;
      Step3-- Merge M and N;

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int insert(int M, int N, int i, int j)
{
    int a=~0<<(j+1);
    int b=(1<<i)-1;  //cannot use (~0)>>30 cuz it is still a negative number!!
	int mask=a|b;
	N=N&mask;
	M=M<<i;
	return N|M;
}

void main()
{
	int M=19;
	int N=1200;
	printf("%d\n", insert(M, N, 2, 6));
}





