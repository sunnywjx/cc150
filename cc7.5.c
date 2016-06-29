/*
cc7.5: Given two squares on a two-dimensional plane, find a line that would cut these two
       squares in half. Assume that the top and the bottom sides of the square run parallel
       to the x-axis.
*/


#include <stdio.h>
#include <stdlib.h>
//double epsilon=0.000001;

typedef struct Point
{
	double x;
	double y;
}Point;

typedef struct line
{
	double slope;
	double y_intercept;
}Line;

typedef struct Square
{
	Point BottomLeft;
	Point TopRight;
}Square;

Point CreatePoint(double x, double y)
{
	Point p;
	p.x=x;
	p.y=y;
	return p;
}

Line CreateLine(Point a, Point b)
{
	Line l;
	l.slope=(a.y-b.y)/(a.x-b.x);
	l.y_intercept=(a.x*b.y-a.y*b.x)/(a.x-b.x);
	return l;
}

Square CreateSquare(Point left, Point right)
{
	Square s;
	s.BottomLeft=left;
	s.TopRight=right;
	return s;
}


Line CutSquareInHalf(Square s1, Square s2)
{
	Point middle1, middle2;
	Line l;
	middle1=CreatePoint((s1.BottomLeft.x+s1.TopRight.x)/2, (s1.BottomLeft.y+s1.TopRight.y)/2);
	middle2=CreatePoint((s2.BottomLeft.x+s2.TopRight.x)/2, (s2.BottomLeft.y+s2.TopRight.y)/2);
    l=CreateLine(middle1, middle2);
    return l;
}



void main()
{
	Point al, ar, bl, br;
	Square s1, s2;
	Line l;
	//printf("hello");

	al=CreatePoint(2, 2);
	ar=CreatePoint(4, 4);
	bl=CreatePoint(-4, 0);
	br=CreatePoint(-2, 2);
	
	s1=CreateSquare(al, ar);
	s2=CreateSquare(bl, br);

	l=CutSquareInHalf(s1, s2);
	printf("Line is %lfx + %lf = y\n", l.slope, l.y_intercept);

}










