/* 
cc1.2: Implement a function void reverse(char *str) in c or c++ which reverse
       a null-terminated string. 

要求：a. do it in place (cannot create a new string).
     b. null character.
思路：a. 首尾字符互换。
     b. 使用指针。


   strlen(str)计算str的长度，不包括null terminator ('\0'是一个character，ascii值为0)。
   NULL是一个pointer，point to nowhere, it holds the 8 bytes address 0x0. While 
   null character is a character, it has the value 0 of 4 bytes int.
*/

#include <stdio.h>
#include <string.h>

/* Time: O(n), Extra Space: O(1) */
void reverse1(char *str)
{
	int i;
	int temp;
	int len=strlen(str); 
	for(i=0;i<len/2;i++)
	{
		temp=str[i];
		str[i]=str[len-1-i];
		str[len-1-i]=temp;
	}
}

/* Time: O(n), Extra Space: O(1) */
void reverse2(char *str)
{
	char *s=str;
	char *e=str;
	char temp;
	while(*e) /* equal to while(*e!='\0'); */ 
		e++;
	e--;
	while(s<e)
	{
		temp=*s;
		*s=*e;
		*e=temp;
		s++;
		e--;
	}
}

void main()
{
	char str[2]="h"; /* char str[]="hello" is ok */
	reverse1(str);
	printf("%s\n",str);
}

