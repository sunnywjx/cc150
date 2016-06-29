/*
cc9.2: Imagine a robot sitting on the upper left corner of grid with r rows and 
       c columns. The robot can only move in two directions,right and down. How 
       many possible paths are there for the robot to go from (0,0) to (r, c)?
       FOLLOW UP
       Imagine certain cells are "off limits" such that the robot cannot step on 
       them. Design an algorithm to find a path for the robot from the top left 
       to the bottom right. 


IDEA:  We need to count the number of ways of making a path with X right steps
       and Y down steps. This path will have X+Y steps in total. To build a path,
       we are essentially selecting X positions to move right out of X+Y steps.
          "RRRDDD......DRDRR"

       This is given by the binomial expression (n choose r):
                      n         n!
                    (   ) = ----------
                      r      r!(n-r)!

                     X+Y     (X+Y)!
             ==>    (   ) = --------
                      X       X!Y!
*/



#include <stdio.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0                      
#define R 5
#define C 5

typedef struct Point
{
	int row;
	int column;
}Point;


Point CreatePoint(int r, int c)
{
	Point p;
	p.row=r;
	p.column=c;
	return p;
}

Point path[R+C-1];
//Time: O(2^(r+c)), cuz rach path has r+c steps, and every step we have two choices.
Point *getPath(int maze[][C])
{
	if(maze==NULL)
		return NULL;
	
	if(get_Path(maze, R-1, C-1, path))
		return path;
	return NULL;
}

int get_Path(int maze[][C], int row, int col, Point *path)
{
	if(col<0||row<0||maze[row][col])
		return FALSE;
	int isAtOrigin=(row==0)&&(col==0);
	if(isAtOrigin||get_Path(maze, row, col-1, path)||get_Path(maze, row-1, col, path))
	{
		Point p=CreatePoint(row, col);
		path[row+col]=p;
		return TRUE;
	}
	return FALSE;
}

/*
Point path[R+C-1];

void initial(int cache[][C]) //not visted:INT_MAX, visted & path:1, visted & no path:0
{
	int i, j;
	for(i=0; i<R; i++)
	{
		for(j=0; j<C; j++)
			cache[i][j]=INT_MAX;
	}
}
//Time: O(rc)
Point *getPath(int maze[][C])
{
	if(maze==NULL)
		return NULL;
	int cache[R][C];
	initial(cache);
	if(get_Path(maze, R-1, C-1, path, cache))
		return path;
	return NULL;
}

int get_Path(int maze[][C], int row, int col, Point *path, int cache[][C])
{
	if(col<0||row<0||maze[row][col])
		return FALSE;
	
	if (cache[row][col]!=INT_MAX)
		return cache[row][col];

	int isAtOrigin=(row==0)&&(col==0);
	int success=0;

	if(isAtOrigin||get_Path(maze, row, col-1, path, cache)||get_Path(maze, row-1, col, path, cache))
	{
		Point p=CreatePoint(row, col);
		path[row+col]=p;
        success=1;
	}
	cache[row][col]=success;
	return success;
}
*/


void main()
{
	int maze[R][C]={
		            {0, 0, 1, 0, 0},
	                {1, 0, 0, 1, 0},
	                {0, 1, 0, 1, 0},
                    {0, 0, 0, 0, 0},
                    {1, 0, 1, 1, 0}
                   };
    Point *path;
    path=getPath(maze);
    int i;
    for(i=0; i<R+C-1; i++)
    {
    	printf("Point(%d, %d)\n", path[i].row, path[i].column);
    }
}













