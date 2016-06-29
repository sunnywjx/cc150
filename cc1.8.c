/*

cc1.8: Assume you have a method isSubstring which checks if one word is a
       substring of another. Given two strings, s1 and s2, write code to 
       check if s2 is a rotation of s1 using only one call to isSubstring
       (e.g., "waterbottle is a rotation of erbottlewat").

思路： s1=  waterbottle
      s2=  erbottlewat
      s2s2=erbottlewaterbottlewat
      isSubstring(s2s2,s1)

  char *strstr(const char *haystack, const char *needle) function finds the
first occurrence of the substring needle in the string haystack. The
terminating '\0' characters are not compared.
  This function returns a pointer to the first occurrence in haystack of any
of the entire sequence of characters specified in needle, or a null pointer
if the sequence is not present in haystack.

  char strcat(char *dest, char *src) the dest should be large enough to contain
the concatenated resulting string.

*/
      
#include <stdio.h>
#include <string.h>

int isSubstring(char str[], char substr[])
{
	if(strstr(str, substr))
		return 1;
	else
		return 0;
}

void rotation(char s1[], char s2[])
{
	int len1=strlen(s1);
	int len2=strlen(s2);
	if(len1!=len2)
	{
		printf("No!\n");
		return;
	}
	char string[2*len2];
	memset(string, '\0', sizeof(string));
	strcpy(string, s2);
	strcat(string, s2);
	if(isSubstring(string, s1))
		printf("Yes!\n");
	else
		printf("No!\n");
	return;
	

}

void main()
{
	char s1[]="waterbottle";
	char s2[]="erbottlewat";
	rotation(s1, s2);
}


