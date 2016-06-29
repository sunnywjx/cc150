/*
cc9.5: Write a method to compute all permutations of a string.

IDEA:  P(a)=a
       P(ab)=ab, ba
       P(abc)=cab, acb, abc, cba, bca, bac

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define L 4

int getFactorial(int n)
{
	int i;
	int result=1;
	for(i=n; i>0; i--)
	{
		result=result*i;
	}
	return result;
}

int num=0;
void get_perms(char prefix[], char remainder[], char result[][L+1])
{
	if(strlen(remainder)==0)
	{
		strcpy(result[num], prefix);
		num++;
		return;
	}
	int len=strlen(remainder);
	int i;
	for(i=0; i<len; i++)
	{
		char before[i+1];
		strncpy(before, remainder, i);
		before[i]='\0';

		char after[len-i+1];
		strcpy(after, remainder+i+1);
		after[len-i]='\0';

		char c[2];
		c[0]=remainder[i];
		c[1]='\0';

        char p[L+1];
        strcpy(p, prefix);
        strcat(p, c);

        char r[strlen(remainder)+1];
        strcpy(r, remainder);
        strcat(before, after);
        strcpy(r, before);
 
		get_perms(p, r, result);
	}
}

void getPerms(char str[], char result[][L+1])
{
	char prefix[L+1]="";
	get_perms(prefix, str, result);
	
}


void main()
{
	char a[L+1]="ABCD";
    int F=getFactorial(L);
	char result[F][L+1];
	int i, j;
	for(i=0; i<F; i++)
	{
		for(j=0; j<L; j++)
			result[i][j]='X';
		result[i][L]='\0';
	}
	getPerms(a, result);
	printf("Num of permutations= %d\n", num);

	for(i=0; i<F; i++)
		printf("%s\n", result[i]);
}