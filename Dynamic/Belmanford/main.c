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
int *dis;
void min_d();
void belman(int x);
void display();
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
    dis=(int*)calloc(g->v,sizeof(int));
    for(int i=0;i<g->v;i++)
        dis[i]=inf;
    g->adj=(int**)calloc(g->v,sizeof(int*));
    for(int i=0;i<g->v;i++)
        g->adj[i]=(int*)calloc(g->v,sizeof(int));
    for(int i=0;i<g->v;i++)
    {
        for(int j=0;j<g->v;j++)
            fscanf(fp,"%d",&g->adj[i][j]);
    }
    belman(0);
}
void min_d(int u,int v)
{
    if((dis[u]+g->adj[u][v])<dis[v])
        dis[v]=dis[u]+g->adj[u][v];
}
void belman(int x)
{ dis[x]=0;
    for(int k=0;k<g->v-1;k++)
    {
        for(int i=0;i<g->v;i++)
        {
            for(int j=0;j<g->v;j++)
            {
                if(g->adj[i][j]!=0 || g->adj[i][j]!=inf)
                    min_d(i,j);
            }
        }
    }
    //detecting negative cycle
    bool flag=false;
    for(int i=0;i<g->v;i++)
        {
            for(int j=0;j<g->v;j++)
            {
                if((g->adj[i][j]!=0 || g->adj[i][j]!=inf) &&(dis[i]+g->adj[i][j])<dis[j])
                   {
                       flag=true;
                       break;
                   }
            }
        }
    if(flag==false)
        display();
    else
        printf("Negative cycle detected..");
}
void display()
{
    printf("Vertex \t Distance from source vertex\n");
    for(int i=0;i<g->v;i++)
        printf("%d \t\t%d\n",i,dis[i]);
}   
