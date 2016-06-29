/*
cc11.5: Given a sorted array of strings which is interspersed with empty strings, write a method to find the 
        location of a given string.


IDEA:   Use binary search!! If the mid is empty, then check mid-1 and mid+1 till find a non-empty string.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 7

typedef struct String
{
	char *str;
}String;

String *create(char a[])
{
	String *s;
	s=(String *)malloc(sizeof(String));
	s->str=(char *)malloc(sizeof(char)*11);
	memset(s->str, '\0', sizeof(s->str));
	strcpy(s->str, a);
	return s;
}


int searchS(String *strings[], String *str, int first, int last)
{
	if(first>last)
		return -1;
	int mid=(last+first)/2;
	if(strlen(strings[mid]->str)==0)
	{
		int left=mid-1;
		int right=mid+1;
		while(1)
		{
			if(left<first&&right>last)
				return -1;
			else if(right<=last&&strlen(strings[right]->str)!=0)
			{
				mid=right;
				break;
			}
			else if (left>=first&&strlen(strings[left]->str)!=0)
			{
				mid=left;
				break;
			}
			right++;
			left--;
		}
	}

	if(strcmp(str->str, strings[mid]->str)==0)
		return mid;
	else if (strcmp(str->str, strings[mid]->str)<0)
		return searchS(strings, str, first, mid-1);
	else
		return searchS(strings, str, mid+1, last);
}


int search(String *strings[], String *str)
{
	if(str->str==NULL||str->str=="")
		return -1;
	else
		return searchS(strings, str, 0, N-1);
}


void main()
{
	String *s[N], *target;
	s[0]=create("abc");
	s[1]=create("ball");
	s[2]=create("");
	s[3]=create("");
	s[4]=create("crab");
	s[5]=create("");
	s[6]=create("daa");
	target=create("daa");

	printf("%d\n", search(s, target));

	int i;
	for(i=0; i<N; i++)
	{
		free(s[i]->str);
		free(s[i]);
	}
	free(target->str);
	free(target);
}