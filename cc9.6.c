/*
cc9.6: Implement an algorithm to print all valid (i.e., properly opened and closed)
       combinations of n-pairs of parentheses.

IDEA:                     (2, 2)
                         /      \
                        /        \
                      "("        return
                     (1, 2)
                    /      \
                   /        \
               "(("          "()"
              (0, 2)        (1, 1)
                    \      /      \
                     \    /        \
                  "(()"  "()("     return
                 (0, 1)  (0, 1)
                       \   \
                        \   \
                    "(())"  "()()"
                    (0, 0)   (0, 0)

*/


#include <stdio.h>
#include <string.h>


void addParens(int leftRem, int rightRem, char str[], int index)
{
	//invalid syntax if right parens are more than left parens (e, g,. "())(" )
	if(leftRem<0||rightRem<leftRem)  
		return;
	if(leftRem==0&&rightRem==0)
	{
		str[index]='\0';
		printf("%s\n", str);
	}
		
	else
	{
		if(leftRem>0)
		{
			str[index]='(';
			addParens(leftRem-1, rightRem, str, index+1);
		}
		if(rightRem>0)
		{
			str[index]=')';
			addParens(leftRem, rightRem-1, str, index+1);
		}
	}
}

void generateParens(int count)
{
	char str[count*2+1];
	addParens(count, count, str, 0);
}


void main()
{
	generateParens(2);
}