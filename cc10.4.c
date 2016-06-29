/*
cc10.4: You have an array with all the numbers from 1 to N, where N is at most 32,000. 
        The array may have duplicate entries and you do not know what N is. With only 
        4 kilobytes of memory available, how would you print all duplicate elements in
        the array?

IDEA:   We have 4 kilobytes of memory which means we can address up to 8*4*2^10 bits.
      Note that 32 * 2^10 bits is greater than 32000. We can create a bit vector with 
      32000 bits, where each bit represents one integer. Using this bit vector, we can 
      then iterate through the array, flagging each element v by setting bit v to 1. 
      When we come across a duplicate element, we print it. 

*/

#include <stdio.h>


void checkDuplicates(int array[], int N)
{
	int bitSet[1000]={0};  //bitSet[1000]
	int i;
    for(i=0; i<N; i++)
    {
    	int pos=array[i]-1;
    	int arr_pos=pos/32;
    	int bit_pos=pos%32;

    	if(bitSet[arr_pos]&(1<<bit_pos))
    		printf("%d\n", array[i]);
    	else
    		bitSet[arr_pos]|=(1<<bit_pos);
    }

}


void main()
{
	int array[11]={1, 2, 3, 4, 4, 100, 99, 56, 100, 32000, 32000};
	checkDuplicates(array, 11);
}




