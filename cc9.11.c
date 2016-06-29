/*
cc9.11: Given a boolean expression consisting of the symbols 0(FALSE), 1(TRUE), 
        &(AND), |(OR) and ^(XOR), and a desired boolean result value result, 
        implement a function to count the number of ways of parenthesizing the 
        expression such that it evaluates to result.
        EXAMPLE 
        countEval("1^0|0|1", false) -> 2
        countEval("0&0&0&1^1|0", true) ->10

IDEA:   countEval( 0^0&0^1|1, TRUE )
      = countEval( 0^(0&0^1|1), TRUE ) + countEval( (0^0)&(0^1|1), TRUE ) +
        countEval( (0^0&0)^(1|1), TRUE ) + countEval( (0^0&0^1)|1, TRUE )

countEval(left|right, TRUE)=countEval(left, TRUE)*countEval(right, FALSE)+
                            countEval(left, TRUE)*countEval(right, TRUE)+
                            countEval(left, FALSE)*countEval(right, TRUE)
countEval(left^right, TRUE)=countEval(left, TRUE)*countEval(right, FALSE)+
                            countEval(left, FALSE)*countEval(right, TRUE)
countEval(left&right, TRUE)=countEval(left, TRUE)*countEval(right, TRUE)

*/




#include <stdio.h>       
#include <string.h>

#define TRUE 1
#define FALSE 0


int countEval(char s[], int result)
{
	if(strlen(s)==0)
		return 0;
	if(strlen(s)==1)
		return s[0]-48==result? 1:0;
	int ways=0;
	int i;
	for(i=1; i<strlen(s); i+=2)
	{
		char c=s[i]; //operator "|", "&" or "^"
        char left[12];
        memset(left, '\0', sizeof(left));
        strncpy(left, s, i);

        char right[12];
        memset(right, '\0', sizeof(right));
        strcpy(right, s+i+1);

        int leftTrue=countEval(left, TRUE);
        int leftFalse=countEval(left, FALSE);
        int rightTrue=countEval(right, TRUE);
        int rightFalse=countEval(right, FALSE);
        int total=(leftTrue+leftFalse)*(rightTrue+rightFalse);

        int totalTrue=0;
        if(c=='^')
        	totalTrue=leftTrue*rightFalse+leftFalse*rightTrue;
        else if (c=='&')
        	totalTrue=leftTrue*rightTrue;
        else if(c=='|')
        	totalTrue=leftTrue*rightTrue+leftTrue*rightFalse+leftFalse*rightTrue;
        
        int subways=result? totalTrue:total-totalTrue;
        ways+=subways;
	}
	return ways;
}

void main()
{
	char str[]="1^0|0|1";
	printf("The result is %d\n", countEval(str, FALSE));
}