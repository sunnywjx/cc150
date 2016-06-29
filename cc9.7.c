/*
cc9.7: Implement the "paint fill" function that one might see on many image editing
       programs. That is, given a screen (represented by a two-dimensional array of
       colors), a point and a new color, fill in the surrounding area until the color
       changes from the original color.

IDEA: 
*/


#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define M 5
#define N 5

typedef enum {Black, White, Red, Yellow, Green, Blue} Color;  // In C, enums are always of type int.

typedef struct point
{
	int r; 
	int c;
}Point;

Point create(int r, int c)
{
	Point p;
	p.r=r;
	p.c=c;
	return p;
}

void paint_fill(Color screen[][N], int r, int c, Color old_c, Color new_c)
{
	if(r<0||r>=M||c<0||c>=N)
		return;
	if(screen[r][c]==old_c)
	{
		screen[r][c]=new_c;
		paint_fill(screen, r-1, c, old_c, new_c);
		paint_fill(screen, r, c-1, old_c, new_c);
		paint_fill(screen, r+1, c, old_c, new_c);
		paint_fill(screen, r, c+1, old_c, new_c);
	}
}

void PaintFill(Color screen[][N], Point p, Color new_c)
{
	if(screen[p.r][p.c]==new_c)  //means the screen is already the color we want
        printf("The screen already has the color you want!\n");			
	else
	    paint_fill(screen, p.r, p.c, screen[p.r][p.c], new_c);
}


void main()
{
	Color screen[M][N]={ 
		                 { White, White, White, White, White },
                         { White, White, White, White, White },
                         { White, White, White, White, White },
                         { White, White, White, White, White },
                         { White, White, White, White, White }
	                   };
	Point p=create(2, 3);
	PaintFill(screen, p, White);
	int i, j;
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("%d ", screen[i][j]);
		}
		printf("\n");
	}

}
