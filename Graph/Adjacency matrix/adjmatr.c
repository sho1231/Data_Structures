#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int count=0;
struct Gra
{
    int v;
    int **adj;
};
void ajd();
void deg();
void edge();
void display();
int main()
{   
    struct Gra *g=(struct Gra *)malloc(sizeof(struct Gra));
    FILE *fp;
    fp= fopen ("Ex.txt", "r");
    if (fp == NULL) 
    { 
    printf("\nError to open the file\n");
    exit (1);
    }
    fscanf(fp,"%d",&g->v);
    g->adj=(int **)malloc(g->v * sizeof(int *));
 for(int i=0;i<g->v;i++)
    g->adj[i]=(int*)malloc(g->v  *sizeof(int));
for(int i=0;i<g->v;i++)
{
    for(int j=0;j<g->v;j++)
        fscanf(fp,"%d",&g->adj[i][j]); //read a graph from file
}
fclose(fp);
deg(g);
 printf("\n");
edge(g);
printf("\n");
 ajd(g);
 printf("\n");
 display(g);
return 0;
}
void display(struct Gra *g)
{
    printf("Displaying:\n");
    for(int i=0;i<g->v;i++)
    {
        for(int j=0;j<g->v;j++)
            printf("%d ",g->adj[i][j]);
        printf("\n");
    }
}
void ajd(struct Gra *g)
{  int s;
   printf("Enter the vertex: ");
   scanf("%d",&s);
   while(s>=g->v)
   {
       printf("Wrong..enter corrrect output:");
       scanf("%d",&s);
   }
   //else{
    
   printf("The adjacents are: ");
   for(int i=0;i<g->v;i++)
   {
       if(g->adj[s][i]==1)
        printf("%d ",i);
   }
   //}
}
void deg(struct Gra *g)
{
    for(int i=0;i<g->v;i++)
    {
        for(int j=0;j<g->v;j++)
        {
            if(g->adj[i][j]==1)
                count++;
        }
    }
    printf("The total degree is: %d",count);
}
void edge(struct Gra *g)
{
    printf("Number of edge of the graph is: %d",(count/2));
}


