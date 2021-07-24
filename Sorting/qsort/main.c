#include <stdio.h>
#include <stdlib.h>
int partition();
void quicksort();
void display(int lb,int ub);
int size;
int *a;
int count=0;
int pass=0;
int main()
{
    printf("Enter the size of array:");
    scanf("%d",&size);
    a=(int*)calloc(size,sizeof(int));
    for(int i=0;i<size;i++)
    {
        printf("Enter element: ");
        scanf("%d",&a[i]);
    }
    int lb=0;
    int ub=size-1;
    quicksort(a,lb,ub);
    printf("Total number of comparison:%d",count);

}
int partition(int a[],int lb,int ub)
{
    int start=lb;
    int p=a[lb];
    int end=ub;
   while(start<end&&++count)
{
    while(a[start]<=p&&++count)
        start++;
    while(a[end]>p&&++count)
        end--;
    if(start<end)
    {
        int temp=a[start];
        a[start]=a[end];
        a[end]=temp;
    }
   }
 int temp=a[end];
    a[end]=a[lb];
    a[lb]=temp;
    return end;
}

void quicksort(int a[],int lb,int ub)
{ int loc;
    if(lb<ub)
    {
        loc=partition(a,lb,ub);
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);
        pass++;
        display(lb,ub);
    }
}
void display(int lb,int ub)
{  printf("Pass %d:",pass);
    for(int j=lb;j<=ub;j++)
    {
        printf("%d ",a[j]);
    }
    printf("\n\n");
}
