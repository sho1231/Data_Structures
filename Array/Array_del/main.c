#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[50],s,pos;
    printf("Enter size:");
    scanf("%d",&s);
    if(s<=50 && s>0)
    { for(int i=0;i<s;i++)
        {
            printf("Enter element number %d:",(i+1));
            scanf("%d",&a[i]);
        }
        printf("Enter postion: ");
        scanf("%d",&pos);
        if(pos<=s && pos>0)
        {
            for(int i=pos-1;i<s-1;i++)
            {
                a[i]=a[i+1];
            }
                s--;
                printf("The array after deletion:\n");
                for(int i=0;i<s;i++)
                    printf("%d\n",a[i]);
        }
        else
            printf("Invalid position..");
    }
    else
        printf("Invalid size..");
    return 0;
}
