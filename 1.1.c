/* 
cc1.1 Implement an algorithm to determine if a string has all unique characters. 
      What if you cannot use additional data structure? 

1. 判断string长度是否大于256，如果大于则有重复字符。
2. 几个思路：
      a. 每个字符逐一跟后面字符比较。
      b. sort然后跟相邻字符比较,需要extra space。
      c. 使用一个array[256]来判断。
      d. 如果都是lower case，则可以使用bit vector。
*/

#include <stdio.h>
#include <string.h>

/*If no return statement appears in a function definition, control automatically
  returns to the calling function after the last statement of the called function
  is executed. In this case, the return value of the called function is undefined.
*/

/* Time: O(n^2), Extra Space: O(1) */
void isUnique1(char a[])
{
	int len, i, j, flag=0;
	len=strlen(a);
	if(len>256)
	{
		printf("The string has duplicate characters!\n");
	    return;
	}	
	for(i=0; i<len; i++)
	{
		for(j=i+1; j<len; j++)
		{
			if(a[i]==a[j])
			{
				flag=1;
				break;
			}	
		}
	}
	if(flag)
		printf("Duplicate!\n");
	else
		printf("Unique!\n");

}

/*---------------------------------------------------------------------------*/
/*
If a function A uses M units of its own space (local variables and parameters), 
and it calls a function B that needs N units of local space, then A overall 
needs M + N units of temporary workspace. If things are passed by pointer or 
reference, then space is shared. For example, if A passes a C-style array to B,
there is no new space allocated. 
*/

/* Time: O(nlogn), Space:O(1) */
/*void sort(char a[]);
//{
	/* QuickSort:no extra space! 
//}

void isUnique2(char a[])
{
	int len=strlen(a);
	int flag=0;
	if(len>256)
	{
		printf("Duplicate!\n");
		return;
	}
	sort(a);
	int i;
	for(i=0; i<len-1; i++)
	{
		if(a[i]==a[i+1])
		{
			flag=1;
			break;
		}
	}
	if(flag)
		printf("Duplicate!\n");
	else
		printf("Unique!\n");
}*/


/*---------------------------------------------------------------------------*/

/* Time: O(n), Space: O(1) means that the memory required by the algorithm is 
   constant, does not depend on the size of the input. 
*/
void isUnique3(char a[])
{
	int i;
	int array[256]={0};
	int len=strlen(a);
	if(len>256)
	{
		printf("Duplicate!\n");
		return;
	}
	for(i=0; i<len; i++)
	{
		if(array[a[i]]==1)
		{
			printf("Duplicate!\n");
			return;
		}
		else
			array[a[i]]=1;
	}
	printf("Unique!\n");
	return;
}


/*---------------------------------------------------------------------------*/

/* 

Inserting a number
If we want to add 7 to the array:
1-> Find the block to which 7 belongs: divide 7 by 8 (since each block is of 8 
    bit). The quotient is the block number . So 7 belongs to the first block.
2-> Find the bit position of 7. Taking the remainder (using the % operator).
    7 % 8 is 7. So the 7th bit in the first block is the position of the number 7. Please note that we are not inserting the number 7 into the array, instead we are setting ( making the bit 1 ) the corresponding bit in the corresponding block .
3-> Setting the bit: ORing the value in the block with 1 leftshited n times(n is
    the bit position).
eg. address[value/8] | (1 << (value%8));

Deleting a number 
1-> Find the position of the number.
2-> Clear the corresponding bit ( Make the bit 0).
3-> Clearing the bit: ANDing the value in the block with the negation of 1
    leftshifted n times (n is the bit position).
eg. address[value/8] & ~(1 << (value%8));

Checking the presence of a number
1-> Find the block to which the number belongs.
2-> Find the bit position.
3-> If the corresponding bit is 0, the number is not present.If the value
    returned by ANDing number in the block with 1 leftshifted n times (n is the
    bit position) is 1, the number is present.
eg. address[value/8] & (1 << (value%8))


/* Time: O(n), Extra Space: O(1) */

int isUnique4(char a[])
{
	int i;
	int flag=0;
	int offset=0;
	int len=strlen(a);
	for(i=0;i<len;i++)
	{
		flag=1<<(a[i]-'A');
		if((offset&flag)!=0)
		{
			//printf("Duplicate!\n");
			return -1;
		}
		else
			offset=flag|offset;
	}
	//printf("Unique!\n");
	return 1;
}

int isUnique5(char s[])
{
	int array[8]={0};
	int i;
    int arrayPos, bitPos;
	for(i=0; i<strlen(s); i++)
	{
        arrayPos=s[i]/32;
        bitPos=s[i]%32;
		if((array[arrayPos]&(1<<bitPos))==0)
			array[arrayPos]|=(1<<bitPos);
		else
		{
			printf("Duplicate!\n");
			return;
		}
	}
	printf("Unique!\n");
}


void main()
{
	char a[3]="11";
	isUnique5(a);
	//isUnique4(a);
}
