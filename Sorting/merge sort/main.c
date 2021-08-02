#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>
int *b;
int count=0;
void copy(int a[],int lb,int ub)
{
    for(int i=0;i<=ub;i++)
        a[i]=b[i];
}
void display(int a[],int size)
{  
    for(int i=0;i<=size;i++)
        printf("%d ",a[i]);
    printf("\n");
}
void merge(int a[],int lb,int mid,int ub);
void merge_sort(int a[],int lb,int ub)
{   
    int mid;
    if(lb<ub)
    {
        mid=((lb+ub)/2);
        merge_sort(a,lb,mid);
        //display(a,ub);
        merge_sort(a,mid+1,ub);
       // display(a,ub);
        merge(a,lb,mid,ub);
        //display(a,ub);
    }
}
void merge(int a[],int lb,int mid,int ub)
{
    int i=lb;
    int j=mid+1;
    int k=lb;
    while(i<=mid&&j<=ub&&++count)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    while(i<=mid&&++count)
    {
        b[k]=a[i];
        k++;i++;
    }
    while(j<=ub&&++count)
    {
        b[k]=a[j];
        k++;j++;
    }
    copy(a,lb,ub);
}
int main()
{  
    int a[]={2,3,1,5,6};
    b=(int*)calloc(5,sizeof(int));
    printf("Array before sorting:\n");
    for(int i=0;i<5;i++)
        printf("%d ",a[i]);
    merge_sort(a,0,4);
    printf("\nArray after sorting:\n");
    display(a,4);
    printf("The number of comparisons:%d",count);
}
