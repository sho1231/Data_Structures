#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>
int size;
void display();
void swap(int a[],int c, int b)
{
    int temp=a[c];
    a[c]=a[b];
    a[b]=temp;
}
int partition(int a[],int lb,int ub)
{ 
    int start=lb;
    int end=ub;
    int pivot=a[lb];
    while(start<end)
    {
        while(a[start]<=pivot)
         start++;
        while(a[end]>pivot)
            end--;
        if(start<end)
            swap(a,start,end);
    }
    swap(a,lb,end);
    return end;
}
void q_sort(int a[],int lb,int ub)
{  
    if(lb<ub)
    {
        int loc=partition(a,lb,ub);//storing the end value
        q_sort(a,lb,loc-1);
        q_sort(a,loc+1,ub);
        display(a,size);
    }
}
void display(int a[],int size)
{
    for(int i=0;i<size;i++)
        printf("%d ",a[i]);
    printf("\n");
}
int main()
{
    printf("Enter the size:");
    scanf("%d",&size);
    int a[size];
    printf("Enter the elements:");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    q_sort(a,0,size-1);
}