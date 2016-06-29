/* 
cc1.3: Given two strings, write a method to decide if one is a permutation
       of the other. 

   要求：1. case sensitive (or not)
        2. white space important (or not)
   思路：a. sort然后逐一比较。
        b. count每个字符出现的次数。
*/

/* Time: O(nlogn), Extra Space: O(1) */
#include <stdio.h>
#include <string.h>

void sort(char a[])
{
    int i,flag;
    char temp;
    do
    {
        flag=0;
        for(i=0;i<strlen(a)-1;i++)
        {
            if(a[i]>a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                flag=1;
            }
        }
    }while(flag);
}

void check1(char a[], char b[])
{
	int len1=strlen(a);
	int len2=strlen(b);
	if(len1!=len2)
	{
		printf("No!\n");
		return;
	}
	sort(a);
	sort(b);
    if(strcmp(a, b)==0)
    	printf("Yes!\n");
    else
    	printf("No!\n");	
}

/* Time: O(n) , Extra Space: O(1) */
void check2(char a[], char b[])
{
	int array[256]={0};
	int len1=strlen(a);
	int len2=strlen(b);
	if(len1!=len2)
	{
		printf("No!\n");
		return;
	}
	int i, j;
	for(i=0;i<len1;i++)
		array[a[i]]++;
	for(j=0;j<len2;j++)
	{
		array[b[j]]--;
		if(array[b[j]]<0) /* cannot use if(array[c]!=0) here */
		{
			printf("No!\n");
			return;
		}
	}	
	printf("Yes!\n");
	return;
}


void main()
{
	char str1[6]="hello";
	char str2[7]="hello";
	check1(str1, str2);
}