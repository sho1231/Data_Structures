// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
struct st
{
  int d;
  struct st *next;
};
struct st *head,*temp,*newnode;
int main() {
    int a[2][2]={{0,1},{1,0}};
     newnode=(struct st*)malloc(sizeof(struct st));
     head=(struct st*)malloc(sizeof(struct st));
     temp=(struct st*)malloc(sizeof(struct st));
    for(int i=0;i<2;i++)
    { 
        head[i];
        for(int j=0;j<2;j++)
        {
            if(a[i][j]==1)
            {
                newnode[i].d=j;
                newnode->next=0;
                if(head==0)
                {
                    head[i]=temp[i]=newnode[i];
                }
                else
                {
                    temp[i].next=newnode;
                    temp[i]=newnode[i];
                }
            }
        }
    }
    printf("%d ",newnode[1].d);
    
    return 0;
}