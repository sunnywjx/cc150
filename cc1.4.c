/*
cc1.4: Write a method to replace all spaces in a string with '%20'. You may assume
       that the string had sufficient space at the end to hold the additional
       characters, and that you are given the "true" length of the string.
       eg. Input:  "Mr John Smith   ", 13
           Output: "Mr%20John%20Smith"

要求：do it in place!
思路：从头开始扫描，计算while space的个数，确定string的心长度。
     从尾部开始扫描，遇见字符则复制，遇见white space则插入'%20'，指针前移。

The C library function int isspace(int c) checks whether the passed character is
white space or not.This function returns a non-zero value(true) if c is a white
space character, else zero (false).Need to include <ctype.h> library.
*/

#include <stdio.h>
#include <string.h>

/* Time: O(n), Extra Space: O(1) */
void space(char str[], int length)
{
	int i, j;
	int count=0;
	int newlength;
	for(i=0;i<length;i++)
	{
		if(str[i]==' ')/* equal to if(isspace(s[i]))*/
			count++;
	}
	newlength=length+count*2;
	str[newlength]='\0';
	for(j=length-1;j>=0;j--)
	{
		if(str[j]!=' ')
		{
			str[newlength-1]=str[j];
			newlength--;
		}
		else
		{
			str[newlength-1]='0';
			str[newlength-2]='2';
			str[newlength-3]='%';
			newlength=newlength-3;
		}	
	}
}


void main()
{
	char str[]="Mr John Smith   ";
	space(str,13);
	printf("%s\n",str);
}