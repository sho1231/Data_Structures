#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define size 5
int top=-1;
int stack [size];
bool isFull()
{
    if(top==size-1)
        return true;
    else
        return false;
}
bool isEmpty()
{
    if(top==-1)
        return true;
    else
        return false;
}
void push(int n)
{
    if(isFull())
        printf("Stack overflow...\n");
    else
    {
        top++;
        stack[top]=n;
       // printf("%d\n",top);
    }
}
void peek()
{
    if(isEmpty())
        printf("Stack Underflow...\n");
    else
    {
        printf("%d\n",stack[top]);
    }
}
void pop()
{
    if(isEmpty())
        printf("Stack Underflow..\n");
    else
    {
        int n=stack[top];
        printf("%d\n",n);
        top--;
    }
}
void display()
{
    if(isEmpty())
        printf("Stack Underflow..\n");
    else
    {
        for(int i=top;i>=0;i--)

            printf("%d\n",stack[i]);
    }
}
int main()
{
    int ch=1;
    while(ch==1)
    {
        printf("1)Push.\n2)Pop.\n3)isFull.\n4)isEmpty.\n5)Display.\n6)Clear screen.\n7)peek.\n8)Exit.\n");
        int c,n;
        printf("Enter choice: ");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d",&n);
            push(n);
            break;
        case 2:
            pop();
            break;
        case 3:
           if(isFull())
                printf("Stack overflow..\n");
           else
                printf("Stack not full..\n");
            break;
        case 4:
            if(isEmpty())
                printf("Stack undeflow..\n");
            else
                printf("Stack not underflow..\n");
            break;
        case 5:
            display();
            break;
        case 6:
            system("cls");
            break;
        case 7:
            peek();
            break;
        case 8:
            printf("exiting..\n");
            ch=0;
            break;
        default:
            printf("Wrong choice...\n");
            break;
        }
    }
    return 0;
}
