#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define inf 99999
struct Gra
{
    int v;
    int **adj;
};
struct Gra *g;
int **p;
void display();
void fw();
void sp();
void dis2();
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
    p=(int **)calloc(g->v,sizeof(int*));
    g->adj=(int **)calloc(g->v,sizeof(int*));
    for(int i=0;i<g->v;i++)
        p[i]=(int*)calloc(g->v,sizeof(int));
    for(int i=0;i<g->v;i++)
        g->adj[i]=(int*)calloc(g->v,sizeof(int));
    for(int i=0;i<g->v;i++)
{
    for(int j=0;j<g->v;j++)
    {
        fscanf(fp,"%d",&g->adj[i][j]);//read a graph from file
        if(g->adj[i][j]==0 || g->adj[i][j]==inf)
            p[i][j]=inf;
        else
            p[i][j]=i;
    } 
}
fw();
//printf("\n\n");
//dis2();
printf("\n\nEnter the source node and destination node: ");
int h,j;
scanf("%d%d",&h,&j);
printf("The shortest path from %d to %d is: ",h,j);
sp(h,j);
   return 0;

}
void sp(int so,int de)
{  
    if(so!=de)
        sp(so,p[so][de]);
    printf("%d ",de);
    return ;
}
void fw()
{
    for(int k=0;k<g->v;k++)//intermediate
    {
        for(int i=0;i<g->v;i++)//starting path
        {
            for(int j=0;j<g->v;j++)//destination path
            {
             if(g->adj[i][k]+g->adj[k][j]<g->adj[i][j])
             {
                g->adj[i][j]=g->adj[i][k]+g->adj[k][j];
                p[i][j]=g->adj[k][j];
             }
            }  
        }
        printf("Pass %d:\n",(k+1));
        display(g);
        printf("\n");
    }
}
void display()
{
    for(int i=0;i<g->v;i++)
    {
        for(int j=0;j<g->v;j++)
           if(g->adj[i][j]==99999)
                printf("INF ");
            else
                printf("%d ",g->adj[i][j]);
        printf("\n");
    }
}
void dis2()
{
      for(int i=0;i<g->v;i++)
    {
        for(int j=0;j<g->v;j++)
           if(p[i][j]==99999)
                printf("INF ");
            else
                printf("%d ",p[i][j]);
        printf("\n");
    }

}