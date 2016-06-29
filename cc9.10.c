/*
cc9.10: You have a stack of boxes, with widths wi, heights hi and depths di. The
        boxes cannot be rotated and can only be stacked on top of one another if
        each box in the stack is strickly larger than the box above it in width, 
        height and depth. Implement a method to build the tallest stack possible,
        where the height of a stack is the sum of the heights of each box.

IDEA:   The biggest stack we can build with all the boxes equals the max of(biggest
        stack with bottom b1, biggest stack with bottom b2,...,biggest stack with
        bottom bn). Then, with a particular bottom, we experiment with different 
        boxes for the second level, and so on. We can sort these boxes based on a
        dimension first, then when we insert a new box in the stack, we don't have
        to check backwards.

*/


#include <stdio.h>

#define MAX(a, b) ((a)>(b)? (a):(b))
#define N 5

typedef struct Box
{
	int width;
	int height;
	int depth;
}Box;

Box CreateBox(int w, int h,  int d)
{
	Box box;
	box.width=w;
	box.height=h;
	box.depth=d;
	return box;
}

/* Time: O(N^2) */
void bubble(Box box[])
{
    int i,flag;
    Box temp;
    do
    {
        flag=0;
        for(i=0;i<N-1;i++)
        {
            if(box[i].height<box[i+1].height)
            {
                temp=box[i];
                box[i]=box[i+1];
                box[i+1]=temp;
                flag=1;
            }
        }
    }while(flag);
}

int AcanBeAboveB(Box A, Box B)
{
	return (B.height-A.height)*(B.width-A.width)*(B.depth-A.depth)>0? 1:0;
}

int createStack(Box boxes[])
{
	bubble(boxes);
	int maxHeight=0;
	//stackMap[i] represents the tallest stack with box i at the bottom.
	int stackMap[N];
	int i;
	for(i=0; i<N; i++)
		stackMap[i]=0;
	for(i=0; i<N; i++)  //get the height if the bottom box is the boxes[i].
	{
		int height=create_stack(boxes, i, stackMap);
		maxHeight=MAX(height, maxHeight);
	}
    return maxHeight;
}

int create_stack(Box boxes[], int bottomIndex, int stackMap[])
{
	if(bottomIndex<N&&stackMap[bottomIndex]>0)
		return stackMap[bottomIndex];
	Box bottom=boxes[bottomIndex];
	int maxHeight=0;
	int i;
	for(i=bottomIndex+1; i<N; i++)
	{
		if(AcanBeAboveB(boxes[i], bottom))
		{
			int height=create_stack(boxes, i, stackMap);
            maxHeight=MAX(maxHeight, height);
		}
	}
	//maxHeight is the height of boxes that above the box bottom.
	maxHeight+=bottom.height; 
	stackMap[bottomIndex]=maxHeight;
	return maxHeight;
}


void main()
{
	Box boxes[N];
	boxes[0]=CreateBox(6, 6, 2);
    boxes[1]=CreateBox(2, 2, 2);
    boxes[2]=CreateBox(3, 3, 3);
    boxes[3]=CreateBox(4, 4, 4);
    boxes[4]=CreateBox(5, 5, 5);
    int i;
    for(i=0; i<N; i++)
    {
    	printf("width= %d, height= %d, depth= %d\n", boxes[i].width, boxes[i].height, boxes[i].depth);
    }
    printf("The maximum height is %d\n", createStack(boxes));
	
}