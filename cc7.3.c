/*
cc7.3: Given two lines on a Cartesian plane (x-y), determine whether the two lines would intersect.

IDEA:  If two lines are the same (same slope and y-intercept), then they are considered to intersect.
       Else, to check if two lines intersect, we just need to check if the slopes are different. Don't
       assume that the slope and y-intercept are integers. Be aware of the limitation of floating point 
       number represetations. Never check for equality with ==. Instead, check if the difference is 
       less than an epsilon (precision) value.

Floating point numbers use a sign, a significand and an exponent.
1. Single precision (float) gives you 23 bits of significand, 8 bits of exponent and 1 bit of sign.
2. Double precision (double) gives you 52 bits of significand, 11 bits of exponent and 1 bit of sign.
*/

#include <stdio.h>
#include <math.h>

double epsilon=0.000001;

typedef struct Line
{
	
	double slope;
	double y_intercept;
}Line;


Line create(double s, double y)
{
	Line a;
	a.slope=s;
	a.y_intercept=y;
	return a;
}

int intersect(Line a, Line b)
{
	return fabs(a.slope-b.slope)>epsilon || fabs(a.y_intercept-b.y_intercept)<epsilon;
}



void main()
{
	Line a, b;
	a=create(2.5555555, 3);
	b=create(2.555555, 4);
	printf("Intersect(1--Yes, 0--No): %d\n", intersect(a, b));

}
