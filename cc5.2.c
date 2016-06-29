/*
cc5.2: Given a real number between 0 and 1 (e.g.,0.72) that is passed in as a double, print the binary
       representation. If the number cannot be represented accurately in binary with at most 32 
       characters, print "ERROR".


char *strcat(char *dest, const char *src)
1. dest -- This is a pointer pointing to the destination array, which should contain a C string, and 
           should be large enough to contain the concatenated resulting string!!!!
2. src -- This is the string to be appended. This should not overlap the destination.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ToBinary(double num, char s[])
{
	double r=0;
	if(num>=1||num<=0)
		return "ERROR";
	while(num>0)
	{
		if(strlen(s)>=32)
			return "ERROR";
		num=num*2;
		if(num>=1)
		{
			strcat(s, "1");
			num=num-1;
		}
		else
		{
			strcat(s, "0");
			//num=r;
		}
	}
	return s;
}


void main()
{
	double num=0.875;
	char s[33]="0."; 
	printf("%zu\n", strlen(s));
	//if we use s[]="0." or s[x]="0."(x<33), segmentation fault will occur!!
	printf("%s\n", ToBinary(num, s));
}



