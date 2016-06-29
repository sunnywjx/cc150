/*
cc11.7: A circus is designing a tower routine consisting of people standing on top of one another's shoulders. 
        For practical and aesthetic reasons, each person must be both shorter and lighter that the person below
        him or her. Given the heights and weights of each person in the circus, write a method to compute the 
        largest possbile number of people in such a tower.
*/



#include <stdio.h>

#define MAX(a, b) ((a)>(b)? (a):(b))
#define N 5

typedef struct Person
{
	int height;
	int weight;
}Person;

Person CreatePerson(int h, int w)
{
	Person p;
	p.height=h;
	p.weight=w;
	return p;
}

/* Time: O(N^2) */
void bubble(Person person[])
{
    int i,flag;
    Person temp;
    do
    {
        flag=0;
        for(i=0;i<N-1;i++)
        {
            if(person[i].height<person[i+1].height)
            {
                temp=person[i];
                person[i]=person[i+1];
                person[i+1]=temp;
                flag=1;
            }
        }
    }while(flag);
}

int AcanBeAboveB(Person A, Person B)
{
	return (B.height-A.height)*(B.weight-A.weight)>0? 1:0;
}

int createTower(Person persons[])
{
	bubble(persons);
	int maxHeight=0;
	//stackMap[i] represents the tallest stack with person i at the bottom.
	int stackMap[N];
	int i;
	for(i=0; i<N; i++)
		stackMap[i]=0;
	for(i=0; i<N; i++)  //get the height if the bottom person is the persons[i].
	{
		int height=create_stack(persons, i, stackMap);
		maxHeight=MAX(height, maxHeight);
	}
    return maxHeight;
}

int create_stack(Person persons[], int bottomIndex, int stackMap[])
{
	if(bottomIndex<N&&stackMap[bottomIndex]>0)
		return stackMap[bottomIndex];
	Person bottom=persons[bottomIndex];
	int maxHeight=0;
	int i;
	for(i=bottomIndex+1; i<N; i++)
	{
		if(AcanBeAboveB(persons[i], bottom))
		{
			int height=create_stack(persons, i, stackMap);
            maxHeight=MAX(maxHeight, height);
		}
	}
	//maxHeight is the height of persons that above the person bottom.
	maxHeight+=bottom.height; 
	stackMap[bottomIndex]=maxHeight;
	return maxHeight;
}


void main()
{
	Person persons[N];
	persons[0]=CreatePerson(6, 6);
    persons[1]=CreatePerson(2, 7);
    persons[2]=CreatePerson(3, 3);
    persons[3]=CreatePerson(4, 4);
    persons[4]=CreatePerson(5, 5);
    int i;
    for(i=0; i<N; i++)
    {
    	printf("height= %d, weight= %d\n", persons[i].height, persons[i].weight);
    }
    printf("The maximum height is %d\n", createTower(persons));
	
}

