#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>
void linear_s(int a[],int s,int k)
{
    int c=0,pos;
    for(int i=0;i<s;i++)
    {
        if(a[i]==k)
        {  pos=i;
            c=1;
            break;
        }
    }
    if(c==0)
        printf("Key not found...");
    else
        printf("%d is present at index %d",k,pos);
}
int main()
    {   int s,key;
        printf("Enter size:");
        scanf("%d",&s);
        int a[s-1];
        for(int i=0;i<s;i++)
        {
            printf("Enter element:");
            scanf("%d",&a[i]);
        }
        printf("\n\n");
        printf("Enter key to be searched:");
        scanf("%d",&key);
        linear_s(a,s,key);
        return 0;
    }