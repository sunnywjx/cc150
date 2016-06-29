/*
cc5.3: Given a positive integer, print the next smallest and the next largest number that have the same
       number of 1 bits in their binary representation.
*/


#include <stdio.h>



unsigned int getNext(unsigned int n)
{
	unsigned int c=n;
	int c0=0;
	int c1=0;
	while(((c&1)==0)&&(c!=0)) 
	{
		c0+=1;
		c>>=1;
	}
	while(((c&1)==1))
	{
		c1+=1;
		c>>=1;
	}
	if((c0+c1==32)||(c0+c1==0)) // it is 32 cuz this is unsigned int(e.g., 11...10...0 or 00...00 or 111...11 ).
		return 0;

	int p=c0+c1;               // position of rightmost non-trailing zero.

    n|=(1<<p);                 // flip the rightmost non-trailing zero to one.
	n&=~((1<<p)-1);            // clean the bits at the right of p.
	n|=(1<<(c1-1))-1;          // add c1-1 ones at the right.

	return n;
}



unsigned int getPrev(unsigned int n)
{
	unsigned int c=n;
	int c0=0;
	int c1=0;
	while(((c&1)==1))
	{
		c1+=1;
		c>>=1;
	}
	if(c==0)                   // e.g., 111...1111 or 00...000 or 00...01...1.
		return 0;
	while(((c&1)==0)&&(c!=0))  
	{
		c0+=1;
		c>>=1;                 
	}

	int p=c0+c1;               // position of rightmost non-trailing one.

	n&=(~0)<<(p+1);            // clean the bits from p.
	int mask=(1<<(c1+1))-1;
	n|=mask<<(c0-1);           // add c1+1 ones at the right of p.
 
	return n;
}


void main()
{
	printf("%u\n", getNext(13948));
	printf("%u\n", getPrev(10115));
}





