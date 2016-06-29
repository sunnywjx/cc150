/*
cc5.5: Write a function to determine the number of bits you would need to flip to convert integer A 
       to integer B.


IDEA: use XOR, each 1 in the XOR represents a bit that is different between A and B. we can use
      num&(1<<i) or (num>>i)&1 to check the ith bit in the num; or we can use num&(num-1) to clean
      the least significant bit in num(see cc5.4)!!!
*/

#include <stdio.h>
#include <stdlib.h>

int Convert1(int a, int b)
{
	unsigned int c;
	int count=0;
	for(c=a^b; c>0; c=c>>1)
	{
		count+=c&1;
	}
	return count;
}

int Convert2(int a, int b)
{
	unsigned int c;
	int count=0;
	for(c=a^b; c>0; c=c&(c-1))
	{
		count++;
	}
	return count;
}


void main()
{
	int a=-15, b=15;
	printf("%d\n", Convert1(a, b));
	printf("%d\n", Convert2(a, b));
}



