#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>
void display();
void insertion(int ar[], int n)
{
    for(int i=0;i<n-1;i++)
    {   int j;
        int temp=ar[i+1];
        int flag=0;
        for(j=i+1;j>0;j--)
        {
            if(ar[j-1]>temp)
            {
                ar[j]=ar[j-1];
                flag=1;
            }
            else
                break;
            
        }
        if(flag==1)
            ar[j]=temp;
         printf("pass%d:\n",i+1);
        display(ar,n);

    }
}
void display(int ar[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",ar[i]);
    }
    printf("\n");
}
int main()
{
    int size;
    printf("Enter the size:");
    scanf("%d",&size);
    int ar[size];
    printf("Enter the elemnts:");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&ar[i]);
    }
insertion(ar,size);
printf("\nThe array after sorting is:\n");
display(ar,size);
}