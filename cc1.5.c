/*
cc1.5: Implement a method to perform basic string compression using the counts 
       of repeated characters. For example, the string aabcccccaa would become
       a2b1c5a3. If the "compressed" string would not become smaller that the 
       original string, your method should return the original string. You can 
       assume the string has only uppercase and lowercase letter.

1. Auxiliary Space is the extra space or temporary space used by an algorithm.
2. Space Complexity of an algorithm is total space taken by the algorithm with 
   respect to the input size. Space complexity includes both Auxiliary space 
   and space used by input.

要求：need to return a string.
思路：通过index往后移来计算字符的出现次数，存入新的字符表，最后比较新旧字符表的大小，返回较小的。

  When you create the local variable it is allocated on the stack. It has a 
lifetime which extends only inside the block in which it is defined. The moment 
the control goes outside the block, the storage for thevariable is no more 
allocated (not guaranteed).   

  The preferable way would be using malloc() to reserve non-local memory. The
memory allocated from the heap, which has a lifetime that spans the entire 
execution of the program. Therefore you can access the memory location from any
block and any time while the program is running.

  One important thing is that you have to deallocate (free()) everything you
allocated by using malloc(). If you forget, you create a memory leak. Once you
free the memory, you can't access that block again.

e.g.
char * greet() 
{
   char * c = (char *) malloc(strlen("Hello")+1);   +1 for the null 
   strcpy(c, "Hello");
   return c;
}
  But now you have to make sure that memory is freed somehow, or else you have a
memory leak.

void main()
{
    printf("%s\n", greet());
}
  This has a leak; the pointer to the malloc'ed memory is returned, the printf
uses it, and then it's lost; you can't free it any longer. 

void main()
{
    char * cp ;
    cp = greet();
    printf("%s\n", cp);
    free(cp);
}
  This doesn't leak, because the pointer is saved in an auto variable cp long
enough to call free() on it. Now, even though cp disappears as soon as
execution passes the end brace, since free has been called, the memory is
reclaimed and didn't leak.

  Another choice would be to allocate it statically in scope:
char * greet() 
{
    static char c[] = "Hello";
    return c;
}
because static memory is allocated separately from the stack in data space.

*/

#include <stdio.h>
#include <string.h>

/* Time: O(n), Extra Space: O(n) */
char *compress(char a[])
{
	int count=1;
	int i, j=0;
	int len=strlen(a);
	char res[2*len];
  memset(res, '\0', sizeof(res));
	for(i=0; i<len; i++)
	{
		if(a[i]==a[i+1])
			count++;
		else
		{
			res[j]=a[i];
			res[j+1]=count+'0';
			count=1;
			j+=2;
		}

	}
	//res[j]='\0';
	return strlen(res)>len? a:strcpy(a,res);
}

void main()
{
	char a[]="aaabbcdddaa";
	printf("%s\n",compress(a));

}