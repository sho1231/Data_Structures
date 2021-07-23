#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
struct Gra
{
    int v;
    int **adj;
};
int *check;
int *stack;
int top=-1;
struct Gra *g;
void push();
bool isEmpty();
bool isFull();
void pop();
void dfs();
int main()
{
    g=(struct Gra*)malloc(sizeof(struct Gra));
     FILE *fp;
    fp= fopen ("testcase2.txt", "r");
    if (fp == NULL)
    {
    printf("\nError to open the file\n");
    exit (1);
    }
    fscanf(fp,"%d",&g->v);
    check=(int *)malloc(g->v*sizeof(int));
    stack=(int*)malloc(g->v*sizeof(int));    
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
dfs(0);
return 0;
}
bool isEmpty()
{
    if(top==-1)
        return true;
    else
        return false;
}
void pop()
{
    if(isEmpty())
        printf("Stack Underflow..\n");
    else
    {
        int n=stack[top];
        printf("%d ",n);
        top--;
    }
}
void push(int x)
{
    if(isFull())
        printf("Stack overflow...\n");
    else
    {
        top++;
        stack[top]=x;
       // printf("%d\n",top);
    }
}
bool isFull()
{
    if(top==(g->v-1))
        return true;
    else
        return false;
}
void dfs(int x)
{
    push(x);
    check[x]=2;
    while(!isEmpty())
    {
        int temp=stack[top];
        pop();
        for(int i=0;i<g->v;i++)
        {
            if(g->adj[temp][i]==1&&check[i]==1)
                    {
                        push(i);
                        check[i]=2;
                    }
        }
    }
}
