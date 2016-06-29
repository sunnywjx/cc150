/*
cc1.7: Write an algorithm such that if an element in an MxN matrix is 0, its
       entire row and column are set to 0.

思路：1. 使用一个flag矩阵来记录原矩阵中0的位置，然后再扫描flag来设原矩阵对应行列为0。
     2. 使用两个array(row[M],col[N]),但凡matrix[i][j]=0则设row[i]=1,col[j]=1;
        此方法类似于cc1.1的思路c。
     3. 用matrix的第一行和第一列来代表row[]和column[]，没有用到extra space。首先，检查
        1st row和1st column是否有0，有则标注one flag为1。之后检查剩余的matrix是否有0，
        有则把映射到第一行和第一列的位置的数值改为0。然后扫描第一行和第一列，把对应的整列和整
        行改为0。最后若是第一行或第一列的flag为1，则把第一行或第一列改为0。


int a[M][N]={0};
  means: "initialize the very first column in the first row to 0, and all
  other items as if they had static storage duration, set them to zero."

int a[M][N]={1};
  means: "initialize the very first column in the first row to 1 and set all
  other items to zero".

  There is a rule in C saying that all objects of static storage duration,
that are not explicitly initialized by the programmer, must be set to zero.

*/
#include <stdio.h>
#include <string.h>

#define M 5
#define N 4

/* Time:O(NM^2); Extra Space:O(MN) */
void zero1(int matrix[M][N])
{
	int flag[M][N]={0};
	int i, j, a, b, x, y;
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			if(matrix[i][j]==0)
				flag[i][j]=1;
		}
	}
    for(x=0; x<M; x++)
	{
		for(y=0; y<N; y++)
		{
			if(flag[x][y]==1)
			{
				for(a=0; a<M; a++)
					matrix[a][y]=0;
				for(b=0; b<N; b++)
					matrix[x][b]=0;
			}	
		}
	}
}


/* Time:O(MN), Extra Space:O(N) */
void zero2(int matrix[M][N])
{
	int row[M]={0};
	int col[N]={0};
	int i, j, a, b;
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			if(matrix[i][j]==0)
			{
				row[i]=1;
				col[j]=1;
			}
		}
	}
	for(i=0; i<M; i++)
	{
		if(row[i])
		{
			for(a=0; a<N; a++)
				matrix[i][a]=0;
		}
	}
	for(j=0; j<N; j++)
	{
		if(col[j])
		{
			for(b=0; b<M; b++)
				matrix[b][j]=0;
		}
	}
}


/* Time:O(MN), Extra Space:O(1) */
void zero3(int matrix[M][N])
{
	int row=0, col=0;
	int i, j;
	for(j=0; j<N; j++)
	{
		if(matrix[0][j]==0)
		{
			row=1;
			break;
		}
	}
    for(i=0; i<M; i++)
	{
		if(matrix[i][0]==0)
		{
			col=1;
			break;
		}
	}

	for(i=1; i<M; i++)
	{
		for(j=1; j<N; j++)
		{
			if(matrix[i][j]==0)
			{
				matrix[i][0]=0;
				matrix[0][j]=0;
			}
		}
	}

	for(j=1; j<N; j++)
	{
		if(matrix[0][j]==0)
		{
			for(i=0; i<M; i++)
				matrix[i][j]=0;
		}
	}
	for(i=1; i<M; i++)
	{
		if(matrix[i][0]==0)
		{
			for(j=0; j<N; j++)
				matrix[i][j]=0;
		}
	}

	if(row)
	{
		for(j=0; j<N; j++)
			matrix[0][j]=0;
	}
	if(col)
	{
		for(i=0; i<M; i++)
			matrix[i][0]=0;
	}
}


void main()
{
	int a[M][N]={
		            {0,12,13,14},
		            {21,22,23,24},
		            {31,32,33,34},
		            {41,42,0,44},
		            {51,52,53,54}
		        };
    int i, j;
    zero(a);
    for(i=0; i<M; i++)
	{
		for(j=0; j>N; j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}







