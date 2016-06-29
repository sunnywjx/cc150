/*
cc5.8: A monochrome screen is stored as a single array of bytes, allowing eight consecutive pixels to be stored 
       in one byte. The screen has width w, where w is divisible by 8 (that is, no byte will be split across
       rows). The height of the screen, of course, can be derived from the length of the array and the width. 
       Implement a function which draws a horizontal line from (x1, y) to (x2, y).
       The method signature should look something like:
       drawLine(byte[] screen, int width, int x1, int x2, int y)
*/


#include <stdio.h>
#define N  9 //3*3 bytes

//width, x1, x2 are in pixels.
//screen, y and height are in bytes.

void drawLine(unsigned char screen[], int width, int x1, int x2, int y) 
{
    int height = N / (width/8); //in bytes
    if (width < 0 || x1 < 0 || x2 < 0 || y < 0 || x1 > width - 1 || x2 > width-1 || y > height -1)
    	return;
    if (x1 > x2) 
    	return;

    // set start element bits and end element  bits
    int startBit = x1 % 8;
    int startByte = x1 / 8 ;
    if(startBit!=0)
    	startByte++;

    int endBit = x2 % 8;
    int endByte = x2 / 8 ;
    if(endBit!=7)
    	endByte--;
    
    //set full bytes
    int i;
    for (i = startByte; i <=endByte; i++) 
    		screen[(width*y)/8+i] = 255;
    
    //create masks for start and end of line 
    unsigned char startMask= 255>>startBit;
    unsigned char endMask=~(255>>(endBit+1));
    
    //set start and end of line
    if((x1/8)==(x2/8))   //x1 and x2 are in the same byte
    {
    	unsigned char mask=startMask&endMask;
    	screen[(width*y)/8+(x1/8)]|=mask;
    }
    else
    {
    	if(startBit!=0)
    		screen[(width*y)/8+startByte-1]|=startMask;
    	if(endBit!=7)
    		screen[(width*y)/8+endByte+1]|=endMask;
    }
    	  
}


void display(unsigned char screen[])
{
    printf("%d %d %d\n", screen[6], screen[7], screen[8]);
    printf("%d %d %d\n", screen[3], screen[4], screen[5]);
	printf("%d %d %d\n", screen[0], screen[1], screen[2]);
}
void main()
{
	unsigned char screen[N]={0};  //3x3
	drawLine(screen, 24, 7, 17, 1);
	display(screen);
}






