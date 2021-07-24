#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>
void swap(int a[],int i,int min)//to swap values
{
     int temp=a[i];
        a[i]=a[min];
       a[min]=temp;
}
void selection_s(int a[],int size)//to sort
{
    for(int i=0;i<size-1;i++)
    { 
        int min=i;
        for(int j=(i+1);j<size;j++)
        {  
            if(a[min]>a[j])
                min=j;
        }
        swap(a,i,min);//calling this function to swap the min value with the i'th index
    }
}
int main()
{  
    int s;
    printf("Enter size: ");
    scanf("%d",&s);
    int a[s];
    for(int i=0;i<s;i++)
    {
        printf("Enter element: ");
        scanf("%d",&a[i]);
    }
    printf("\n\nArray before sorting is:\n");
    for(int i=0;i<s;i++)
        printf("%d ",a[i]);
    selection_s(a,s);
    printf("\n\nArray after sorting is:\n");
    for(int i=0;i<s;i++)
        printf("%d ",a[i]);
    return 0;
}