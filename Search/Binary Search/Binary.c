#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>
void bubble_sort(int a[],int size)//for sorting
    {
        for(int i=0;i<size-1;i++)
        {
            int f=0;
            for(int j=0;j<size-i-1;j++)
            { 
                if(a[j]>a[j+1])
                {
                    int temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    f=1;
                }
            }
            if(f==0)
                break;
        }
    }
int binary_s(int a[],int key,int l,int r)//for searching.
{   bubble_sort(a,r);// calling bubble_sort() for sorting the array if its unsorted.
    int mid;
  int u=r-1;
    while(l<=u)
    {   
        mid=(l+u)/2;
        if(a[mid]<key)
            l=mid+1;
        else if(a[mid]>key)
            u=mid-1;
        else
            {
                return mid;
                break;
            }
    }
    return -1;
}
int main()
    {
        int size,key;
        printf("Enter sorted array....\n\n");
        printf("Enter size of the array: ");
        scanf("%d",&size);
        int a[size];
        printf("\n");
        for(int i=0;i<size;i++)
        {
            printf("Enter element: ");
            scanf("%d",&a[i]);
        }
        printf("\n");
        printf("Enter key: ");
        scanf("%d",&key);
        int re=binary_s(a,key,0,size);
        if(re>-1)
            printf("%d is present at index %d",key,re);
        else
            printf("%d is not present.",key);
        return 0;
    }