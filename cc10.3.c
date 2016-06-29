/*
cc10.3: Given an input file with four billion non-negative integers, provide an algorithm to generate an integer 
        which is not contained in the file. Assume you have 1GB of memory available for this task.
        FOLLOW UP
        What if you have only 10MB of memory? Assume that all the values are distinct and we now have no more than
        one billion non-negative integers.

NOTE: KB = 2^10 bytes
      MB = 2^20 bytes
      GB = 2^30 bytes

*/

#include <stdio.h>  
#include <math.h> 

void main()   
{
	FILE *fp;
	fp=fopen("input.txt", "r");

	unsigned int array[2]={0};  //125,000,000
	unsigned int i;
	while(!(feof(fp)))
	{
		fscanf(fp, "%u", &i);
		unsigned int bitPos=i%32;
		unsigned int arrayPos=i/32;
		array[arrayPos]|=(1<<bitPos);
		
	}
	fclose(fp);
	unsigned int index, number;
	for(index=0; index<2; index++)
	{
		if(array[index]!=4294967295)
		{
			unsigned int offset=log(4294967295-array[index])/log(2);
			number=index*32+offset;
			printf("The number is %u\n", number);
		}
	}
}   