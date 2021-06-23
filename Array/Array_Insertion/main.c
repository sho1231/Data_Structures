#include <stdio.h>
#include <stdlib.h>

int main()
{


    int a[50],s,n,pos;
    printf("Enter the size: ");
    scanf("%d",&s);
    if(s<=50 && s>0)
    {
        for(int i=0;i<s;i++)
        {
            printf("Enter element number %d:",(i+1));
            scanf("%d",&a[i]);
        }
        printf("\nEnter pos and element:");
            scanf("%d%d",&pos,&n);
            if(pos>s||pos<1)
                printf("Position does not exists...\n");
            else
            {
                for(int i=s-1;i>=(pos-1);i--)
                {
                    a[i+1]=a[i];
                    if(i==(pos-1))
                    {   a[i]=n;
                        s++;
                    }
                }
                printf("The array after insertion..\n");
                for(int i=0;i<s;i++)
                        printf("Element in postition %d:%d\n",(i+1),a[i]);

            }
    }
    else
        printf("Invalid size...\n");

    return 0;
}
