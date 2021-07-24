#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>
void bubble_sort(int a[],int size)
    {
        for(int i=0;i<size-1;i++)
        {
            int f=0;
            printf("Pass %d:",(i+1));
            for(int j=0;j<size-i-1;j++)
            { 
                if(a[j]>a[j+1])
                {
                    int temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    f=1;
                 for(int k=0;k<size;k++)
                    printf("%d ",a[k]);
                  printf("\n");
                }
            }
            printf("\n\n");
            if(f==0)
                break;
        }
    }
int main()
    {   int s;
    printf("Enter size:");
    scanf("%d",&s);
    int a[s-1];
    for(int i=0;i<s;i++)
    {
        printf("Enter element:");
        scanf("%d",&a[i]);
    }
    printf("\n\n");
    bubble_sort(a,s);
    printf("\nThe final sorted array is:\n");
    for(int i=0;i<s;i++)
        printf("%d ",a[i]);
    return 0;
    }