#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>
int size;
void display(int a[])
{
    for(int i=0;i<size;i++)
        printf("%d ",a[i]);
    printf("\n");
}
void swap(int a[],int i,int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
void selection(int a[])
{ int pass=0;
    for(int i=0;i<size-1;i++)
    {  
        int min=i;
        for(int j=i+1;j<size;j++)
        {
            if(a[j]<a[min])
            {
               min=j;
            }
        }
        if(i!=min)
        { pass++;
         swap(a,min,i);
         printf("Pass%d:\n",pass);
         display(a);
        }
    }
}
int main()
{
    printf("Enter the size:");
    scanf("%d",&size);
    int a[size];
    printf("Enter the elements:");
    for(int i=0;i<size;i++)
        scanf("%d",&a[i]);
    selection(a);

}