#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int binary_rec(int a[],int key,int l,int r)
{  int found=-1;
   int mid=(l+r)/2;
   if(l>r)
      found=-1;
   else
   {
       if(key>a[mid])
        l=mid+1;
       else if(key<a[mid])
        r=mid-1;
       else
       {
        found=mid;
       }
   }
   return found;
   return binary_rec(a,key,l,r);
}
/*void binary(int a[],int key,int size)
{
    int l=0;
     bool found=false;
    int r=size-1;
    int mid;
   // printf("%d\n",r);
   while(l<=r)
    {
        mid=((l+r))/2;
        //printf("%d %d %d\n",l,r,mid);
        if(key>a[mid])
            l=mid+1;
        else if(key<a[mid])
            r=mid-1;
        else if(key==a[mid])
        {
            found=true;
            break;
        }
    }
    if(found==true)
        printf("%d is present at index %d.\n",key,mid);
    else
        printf("%d is not present in this array.\n",key);
}*/
int main()
{
    int s,key;
    printf("Enter size:");
    scanf("%d",&s);
    int a[s-1];
    for(int i=0;i<s;i++)
    {
        printf("Enter element:");
        scanf("%d",&a[i]);
    }
   printf("Enter the element to be searched: ");
   scanf("%d",&key);
   if(binary_rec(a,key,0,s-1)>-1)
    printf("true");
   else
        printf("false");
    return 0;
}
