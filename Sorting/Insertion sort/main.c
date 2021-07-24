#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>
void insertion(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int temp=a[i];
        int j=i-1;
        while(j>=0&& a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
int main()
{
    int s;
    printf("Enter the size:");
    scanf("%d",&s);
    int a[s];
    for(int i=0;i<s;i++)
    {
        printf("Enter element: ");
        scanf("%d",&a[i]);
    }
    insertion(a,s);
    printf("\n\n");
    for(int i=0;i<s;i++)
        printf("%d ",a[i]);    
    return 0;
}