#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>
struct G
{
    int v;
    int adjm[100][100];
};
int count=0;;
void ADJ_Ma(struct G *g)
{  
    
    if(!g)
        printf("Memory not allocated..\n");
    else
    {
        printf("Enter number of nodes: ");
        scanf("%d",&g->v);
        for(int i=0;i<g->v;i++)
        {
            for(int j=0;j<g->v;j++)
            {
                printf("Enter in row %d and in column %d:",i,j);
                scanf("%d",&g->adjm[i][j]);
            }
            printf("\n");
        }

    }
}
void DisAjd(struct G *g)
{
    printf("Enter node: ");
    int node;
    scanf("%d",&node);
    for(int i=0;i<g->v;i++)
        {
            if(g->adjm[node][i]==1)
                printf("%d ",i);
        }
}
void display(struct G *g)
{    
        for(int i=0;i<g->v;i++)
        {
            for(int j=0;j<g->v;j++)
                printf("%d ",g->adjm[i][j]);
            printf("\n");
        }
}
void degree(struct G *g)
{
    int ver=g->v;
    for(int i=0;i<ver;i++)
    {
        for(int j=0;j<ver;j++)
        {
                if(g->adjm[i][j]==1)
                    count++;
                        
        }
    }
     printf("Degree of graph:%d",count);
}
void edges(struct G *g)
{
   
   printf("The edges are: %d",(count/2));
}

int main()
    { 
        struct G *g=(struct G *)malloc(sizeof(struct G));
        ADJ_Ma(g);
        printf("\n");
        DisAjd(g);
        printf("\n");
        degree(g);
        printf("\n");
        edges(g);
        printf("\n");
        display(g);
        printf("\n%d",count);
        return 0;

    }