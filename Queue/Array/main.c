#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define size 5
int queue [size-1];
int rear=-1;
int front =-1;
bool isEmpty()
{
    if(front==-1 && rear==-1)
        return true;
    else
        return false;
}
bool isFull()
{
    if(rear==size-1)
        return true;
    else
        return false;
}
void enqueue(int x)
{
    if(front ==-1 && rear ==-1)
    {
        front++;
        rear++;
        queue[front]=x;
    }
    else
    {
        rear++;
        queue[rear]=x;
    }
}
void dequeue()
{
    if(isEmpty())
        printf("Stack Underflow...\n");
    else if(front==rear && front>-1)
    {
        printf("%d\n",queue[front]);
        front=-1;rear=-1;
    }

    else
    {
        printf("%d\n",queue[front]);
        front++;
    }
}
void peek()
{   if(isEmpty())
        printf("Queue undeflow..\n");
    else
        printf("%d\n",queue[front]);
}
void display()
{
    if(isEmpty())
        printf("Stack undeflow..\n");
    else
    {
        for(int i=front;i<=rear;i++)
            printf("%d\n",queue[i]);
    }
}
int main()
{
    int ch=1;
    while(ch==1)
    {
        printf("1)Enqueue.\n2)Dequeue.\n3)isFull.\n4)isEmpty.\n5)Display.\n6)Peek.\n7)Clear the screen.\n8)Exit.\n");
        int c,n;
        printf("Enter choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                if(isFull())
                    printf("Queue overflow..\n");
                else
                {
                printf("Enter data: ");
                scanf("%d",&n);
                enqueue(n);
                }
                break;
            case 2:
                dequeue();
                break;
            case 3:
                if(isFull())
                    printf("Queue overflow..\n");
                else
                    printf("Queue not full..\n");
                break;
            case 4:
                if(isEmpty())
                    printf("Queue underfow..\n");
                else
                    printf("Queue not empty..\n");
                break;
            case 5:
                display();
                break;
            case 6:
                peek();
                break;
            case 7:
                system("cls");
                break;
            case 8:
                printf("Exiting...\n");
                ch=0;
                break;
            default:
                printf("Wrong message..\n");
                break;
        }

    }
    return 0;
}
