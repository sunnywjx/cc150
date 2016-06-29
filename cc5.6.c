/*
cc5.6: Write a program to swap odd and even bits in an integer with as few instructions as possible.
       (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on.)


IDEA: use odd mask 101010 to AND with the number in order to get the bit on the odd posotion, then right 
      shift by 1 to put them in the even position; use 010101 to AND with the number in order to get the bit
      on the even posotion, then left shift by 1 to put them in the odd position; finally, OR them.
      (for signed int, 10101010 is a negative number, in addition, in C, it will use arithmetic right shift
      for signed int which means that if we right shift 10101010, it will become 11010101; thus, we need to
      use unsigned int, and C will perform logical right shift for unsigned int!!!)


 -o name : create a binary file call name.
 -lm : contain the math library.
*/


#include <stdio.h>
#include <math.h>


unsigned int OddMask()
{
	double i;
	double oddmask=0;
	for(i=1; i<=31; i+=2)
	{
		oddmask+=pow(2, i);
	}
	return (unsigned int)oddmask;
}

unsigned int EvenMask()
{
	double i;
	double evenmask=0;
	for(i=0; i<=30; i+=2)
	{
		evenmask+=pow(2, i);
	}
	return (unsigned int)evenmask;
}



unsigned int SwapOddEven(unsigned int num)
{
	return (((num&OddMask())>>1)|((num&EvenMask())<<1));
}


void main()
{
    printf("%u\n", OddMask());
    printf("%u\n", EvenMask());  
    printf("%u\n", SwapOddEven(13));

}


















