/*
cc9.9: Write an algorithm to print all ways of arranging eight queens on an 8x8
       chess board so that none of them share the same row, column or diagonal. 
       In this case, "diagonal" means all diagonals, not just the two that bisect
       the board.

IDEA: 

ways to arrange 8 queens on an 8x8 chessboard =
    ways to arrange 8 queens on an 8x8 chessboard with queen at (0, 0) +  
    ways to arrange 8 queens on an 8x8 chessboard with queen at (0, 1) +
    ways to arrange 8 queens on an 8x8 chessboard with queen at (0, 2) +
    ways to arrange 8 queens on an 8x8 chessboard with queen at (0, 3) +
    ways to arrange 8 queens on an 8x8 chessboard with queen at (0, 4) +
    ways to arrange 8 queens on an 8x8 chessboard with queen at (0, 5) +
    ways to arrange 8 queens on an 8x8 chessboard with queen at (0, 6) +
    ways to arrange 8 queens on an 8x8 chessboard with queen at (0, 7) 
For each one of them, we have
ways to arrange 8 queens on an 8x8 chessboard with queen at (0, 3) =
    ways to arrange 8 queens on an 8x8 chessboard with queens at (0, 3) and (1, 0)+
    ways to arrange 8 queens on an 8x8 chessboard with queens at (0, 3) and (1, 1)+ 
    ways to arrange 8 queens on an 8x8 chessboard with queens at (0, 3) and (1, 2)+
    ways to arrange 8 queens on an 8x8 chessboard with queens at (0, 3) and (1, 4)+
    ways to arrange 8 queens on an 8x8 chessboard with queens at (0, 3) and (1, 5)+
    ways to arrange 8 queens on an 8x8 chessboard with queens at (0, 3) and (1, 6)+  
    ways to arrange 8 queens on an 8x8 chessboard with queens at (0, 3) and (1, 7)

*/


#include <stdio.h>
#include <limits.h>
#define TRUE 1
#define FALSE 0

int GRID_SIZE=8;

void print(int col[])
{
	int i, j;
	int result[GRID_SIZE][GRID_SIZE];
	for(i=0; i<GRID_SIZE; i++)
	{
		for(j=0; j<GRID_SIZE; j++)
		{
			if(col[i]==j)
				printf("1 ");
			else
				printf("0 ");
		}
		printf("\n");
	}
}
// columns[r]=c means row r has a queen at column c.
void placeQueens(int row, int columns[])
{
	if(row==GRID_SIZE)
	{
        print(columns);
		printf("\n");
	}
	else
	{
		int col;
	    for(col=0; col<GRID_SIZE; col++)
	    {
	    	if(checkValid(columns, row, col))
	    	{
	    		columns[row]=col;
	    		placeQueens(row+1, columns);
	    	}
	    }
    }
}

int checkValid(int columns[], int row1, int column1)
{
	int row2;
	//only check the rows that lower than the current row, 
	//cuz we haven't assign the higher row yet.
	for(row2=0; row2<row1; row2++)  
	{
		int column2=columns[row2];
		if(column1==column2)  //whether at the same column
			return FALSE;
		int columnDistance=abs(column2-column1);
		int rowDistance=abs(row2-row1);
		if(columnDistance==rowDistance)  //whether at the diagonal
			return FALSE;
	}
	return TRUE;
}

void main()
{
	int columns[GRID_SIZE];
	int i;
	for(i=0; i<GRID_SIZE; i++)
	{
		columns[i]=INT_MIN;
	}
	
	placeQueens(0, columns);
}
