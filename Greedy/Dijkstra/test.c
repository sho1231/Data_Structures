#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define inf 99999
struct Gra
{
    int v;
    int **adj;//for storing the cost
};
struct Gra *g;
int *check;//to check the status of nodes whether visted or not
int *dis;// to store the distance
int parent[1000];
void min_d();
void dijk();
int compare();
void display();
void countDistance();
int main()
{   
    g=(struct Gra *)malloc(sizeof(struct Gra));
    FILE *fp;
    fp= fopen ("testcase4.txt", "r");
    if (fp == NULL)
    {
    printf("\nError to open the file\n");
    exit (1);
    }
    fscanf(fp,"%d",&g->v);
    check=(int*)calloc(g->v,sizeof(int));//creating check array
    dis=(int*)calloc(g->v,sizeof(int));//creating distance array;
    /*initializing the dis array with infinity and will later change the distane
        for source vertex 0*/
    for(int i=0;i<g->v;i++)
        dis[i]=inf;
    /*initializing the check array with 0*/
    for(int i=0;i<g->v;i++)
        check[i]=0;
    for(int i=0;i<g->v;i++)
        parent[i]=-1;
    //creating the 2d array for adj
    g->adj=(int**)calloc(g->v,sizeof(int*));
    for(int i=0;i<g->v;i++)
        g->adj[i]=(int*)calloc(g->v,sizeof(int));
    //initialing the adj2 array with cost and
    for(int i=0;i<g->v;i++)
    {
      for(int j=0;j<g->v;j++)
        fscanf(fp,"%d",&g->adj[i][j]);//read a graph from file
    }
    dijk();
    return 0;
}
void min_d(int u,int v)
{
    if(dis[u]+g->adj[u][v]<dis[v]){
        dis[v]=dis[u]+g->adj[u][v];
        parent[v] = u;
    }
}
int compare()
{
    int temp;
    //storing a initial value which is not visited to compare
    for(int i=0;i<g->v;i++)
    { 
        if(check[i]==0)
        {
            temp=i;
            break;
        }
    }
    //comparing the initial temp value to get the smallest value which is not visited
     for(int i=0;i<g->v;i++)
    {   
        if(check[i]==0&&dis[i]<dis[temp])
            temp=i;
    }
    return temp;
}
void dijk()
{   
    int u, des;
    printf("Enter the source vertex and destination vertex : ");
    scanf("%d%d",&u,&des);

    dis[u]=0;
    for(int k=0;k<g->v-1;k++)
    {
        int temp=compare();
        check[temp]=1;
    for(int i=0;i<g->v;i++)
    {
        if((g->adj[temp][i]!=0 || g->adj[temp][i]!=inf) &&check[i]==0)
        {   
            min_d(temp,i);
        }
    }
    }

    printf("The shortest path from the source is \n");
    display(des);

    printf("\n");

    printf("The distance is from the source %d to destination %d : \n",dis[des]);
}
void display(int j)
{   
    if (parent[j] == - 1)
        return;
   
    display(parent, parent[j]);
   
    printf("%d ", j);
}
