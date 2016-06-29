/*
cc7.4: Write methods to implement the multiply, subtract, and divide operations for integers.
       Use only the add operator.

IDEA:  1. Substract--we can use ~(b)+1 if allowed or a+negative(b).
       2. Multiply--adding a to itself b times.
       3. Divide--adding b to itself x times to reach a.

*/


#include <stdio.h>


int subtract1(int a, int b)
{
	return a+(~b+1);
}

int negative(int a)
{
	int neg=0;
	int d=a<0? 1: -1;
	while(a!=0)
	{
		neg+=d;
		a+=d;
	}
	return neg;
}

int subtract2(int a, int b)
{
	return a+negative(b);
}

int multiply(int a, int b) //to multiply a by b, just add a to itself b times
{
	if(abs(a)<abs(b))
		return multiply(b, a); //algorithm is faster if abs(b)<abs(a).
	int sum=0;
	int i;
	for(i=abs(b); i>0; i--)
		sum+=a;
	if(b<0)
		sum=negative(sum);
	return sum;
}

// x=a/b ==> a=x*b, then we can know that adding b to itself x times will reach a.
int divide(int a, int b)
{
	if(b==0)
	{
		printf("Divisor cannot be 0!\n");
		return -1;
	}
	int sum=0;
	int x=0;
	while(abs(sum)!=abs(a))
	{
		sum+=b;
		x++;
	}
	return sum==a? x: negative(x);

}



void main()
{
	int a=-6, b=-3;
	printf("a= %d , b= %d\n", a, b);
	printf("a-b= %d\n", subtract1(a, b));
	printf("a*b= %d\n", multiply(a, b));
	printf("a/b= %d\n", divide(a, b));
}




