#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
struct Gra
{
    int v;
    int **adj;
};
struct Gra *g;
int *queue;
int *check;
void enqueue();
void dequeue();
bool isEmpty();
void bfs();
int rear=-1;
int front =-1;
int main()
{
    g=(struct Gra *)malloc(sizeof(struct Gra));
    FILE *fp;
    fp= fopen ("testcase2.txt", "r");
    if (fp == NULL)
    {
    printf("\nError to open the file\n");
    exit (1);
    }
    fscanf(fp,"%d",&g->v);
    check=(int *)malloc(g->v*sizeof(int));
    queue=(int *)malloc(g->v*sizeof(int));
    g->adj=(int **)malloc(g->v * sizeof(int *));
    for(int i=0;i<g->v;i++)
        check[i]=1;
 for(int i=0;i<g->v;i++)
    g->adj[i]=(int*)malloc(g->v  *sizeof(int));
for(int i=0;i<g->v;i++)
{
    for(int j=0;j<g->v;j++)
        fscanf(fp,"%d",&g->adj[i][j]); //read a graph from file
}
enqueue(0);
check[0]=2;
bfs();

return 0;
}
void enqueue(int x)
{
    if(front ==-1 && rear ==-1)
    {
        front++;
        rear++;
        queue[front]=x;
    }
    else
    {
        rear++;
        queue[rear]=x;
    }
}
void dequeue()
{
    if(isEmpty())
        printf("Stack Underflow...\n");
    else if(front==rear && front>-1)
    {
            printf("%d ",queue[front]);
        front=-1;rear=-1;
    }

    else
    {
        printf("%d ",queue[front]);
        front++;
    }
}

bool isEmpty()
{
    if(front==-1 && rear==-1)
        return true;
    else
        return false;
}
void bfs()
{  
    if(isEmpty())
        return ;
    int temp=queue[front];
    dequeue();
    for(int i=0;i<g->v;i++)
    {
        if(g->adj[temp][i]==1&&check[i]==1)
        {
            enqueue(i);
            check[i]=2;
        }
    }
    bfs();
}
   


