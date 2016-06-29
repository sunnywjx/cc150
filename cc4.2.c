
/*
cc4.2: Given a directed graph, design an algorithm to find out whether there is a route between two 
       nodes. 

void assert(int expression);
  assert is a macro which is useful to check certain conditions at run time (when the program is under 
execution) and is very useful while debugging a program. To use it you must include the header file 
"assert.h" in your program. Expression is any valid c language expression, mostly it's a condition.
When condition holds true, the program execution will continue; otherwise it will terminate and an 
error message is displayed on screen(displaying filename, line number, function name, condition) which
does not hold true.

IDEA: 1. BFS(iterative, need queue!!)
      2. DFS(recursive!!)need to use res||DFS() cuz this is similar to 4.1 which need to keep the result
         from bottom to top!!

*/


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define Vertices   6

typedef struct Queue
{
        int capacity;
        int size;
        int front;
        int rear;
        int *elements;
}Queue;

Queue * CreateQueue()
{
        
        Queue *Q;
        Q = (Queue *)malloc(sizeof(Queue));
        
        Q->elements = (int *)malloc(sizeof(int)*Vertices);
        Q->size = 0;
        Q->capacity = Vertices;
        Q->front = 0;
        Q->rear = -1;
        return Q;
}
void Dequeue(Queue *Q)
{
        /* If Queue size is zero then it is empty. So we cannot pop */
        if(Q->size==0)
        {
                printf("Queue is Empty\n");
                return;
        }
        /* Removing an element is equivalent to incrementing index of front by one */
        else
        {
                Q->size--;
                Q->front++;
                /* As we fill elements in circular fashion */
                if(Q->front==Q->capacity)
                {
                        Q->front=0;
                }
        }
        return;
}
int Front(Queue *Q)
{
        if(Q->size==0)
        {
                printf("Queue is Empty\n");
                exit(0);
        }
        /* Return the element which is at the front*/
        return Q->elements[Q->front];
}
void Enqueue(Queue *Q,int element)
{
        /* If the Queue is full, we cannot push an element into it as there is no space for it.*/
        if(Q->size == Q->capacity)
        {
                printf("Queue is Full\n");
        }
        else
        {
                Q->size++;
                Q->rear = Q->rear + 1;
                /* As we fill the queue in circular fashion */
                if(Q->rear == Q->capacity)
                {
                        Q->rear = 0;
                }
                /* Insert the element in its rear side */ 
                Q->elements[Q->rear] = element;
        }
        return;
}



int BFS(int graph[][Vertices], int *visited, int presentVertex, int des)
{
        visited[presentVertex] = 1;
        /* Iterate through all the vertices connected to the presentVertex and perform bfs on those
           vertices if they are not visited before */
        Queue *Q = CreateQueue();
        Enqueue(Q,presentVertex);
        while(Q->size)
        {
                presentVertex = Front(Q);
                //printf("Now visiting vertex %d\n",presentVertex);
                Dequeue(Q);
                int iter;
                for(iter=0;iter<Vertices;iter++)
                {
                        if(graph[presentVertex][iter]==1&&!visited[iter])
                        {
                                visited[iter] = 1;
                                if(iter==des) 
                                {
                                   free(Q->elements);
                                   free(Q); 
                                   return 1;
                                }
                                    
                                Enqueue(Q,iter);
                        }
                }
        }
        free(Q->elements);
        free(Q);
        return 0;
}




int DFS(int graph[][Vertices], int visited[], int presentVertex, int des)
{
        int res=0;
        //printf("Now visiting vertex %d\n",presentVertex);
        visited[presentVertex] = 1;
        /* Iterate through all the vertices connected to the presentVertex and perform dfs on those
           vertices if they are not visited before */
        int iter;
        for(iter=0;iter<Vertices;iter++)
        {
                if(graph[presentVertex][iter]==1&&!visited[iter])
                {
                        //printf("%d, %d, %d   ", presentVertex, iter, des);
                        //int i;
                        //for(i=0; i<Vertices; i++)
                        //    printf("%d ", visited[i]);
                        //printf("\n");
                        if(iter==des)
                            return 1;
                        res=res||DFS(graph, visited, iter, des);
                }
        }
        return res;
        

}



int main()
{ 
        int visited[Vertices]={0};
        int i,j;
       /* int graph[Vertices][Vertices]={
                                             {0, 1, 0, 1},
                                             {0, 0, 0, 1},
                                             {0, 1, 0, 0},
                                             {0, 0, 1, 0}
                                      };*/
        
        int graph[Vertices][Vertices]={
                                             {0, 1, 0, 0, 1, 1},
                                             {0, 0, 0, 1, 1, 0},
                                             {0, 1, 0, 0, 0, 0},
                                             {0, 0, 1, 0, 1, 0},
                                             {0, 0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0, 0}
                                      };
        /* vertices represent number of vertices and edges represent number of edges in the graph. */
        /*scanf("%d%d",&vertices,&edges);
        int vertex1,vertex2;
        for(iter=0;iter<edges;iter++)
        {
                scanf("%d%d",&vertex1,&vertex2);
                assert(vertex1>=0 && vertex1<vertices);
                assert(vertex2>=0 && vertex2<vertices);
                graph[vertex1][vertex2] = 1;
                size[vertex1]++;
        }*/

        /*for(i=0; i<Vertices; i++)
        {
            for(j=0; j<Vertices; j++)
            {
            	printf("%d ",graph[i][j]);
            }
            printf("\n");
        	  
        }*/

        //printf("check:(1--has route!, 0--no route!) %d\n", BFS(graph, 0, visited, 3));
        printf("check:(1--has route!, 0--no route!) %d\n", BFS(graph, visited, 1, 5));
        //DFS(graph, 0, visited, 5);   
        return 0;



}









