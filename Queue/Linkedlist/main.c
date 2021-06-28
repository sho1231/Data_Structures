#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    int d;
    struct node *adr;
};
struct node *head,*newnode,*temp;
int count=0;
bool isEmpty()
{
    if(head==0)
        return true;
    else
        return false;
}
void enqueue(int x)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->d=x;
    newnode->adr=0;
    if(isEmpty())
        head=newnode;
    else
        temp->adr=newnode;
    temp=newnode;
    count++;
}
void dequeue()
{
    if(count<2)
    {
        free(head);
        head=0;
    }
    else
    {
        struct node *t;
        t=head->adr;
        free(head);
        head=t;
    }
    count--;
}
int peek()
{
    return head->d;
}
void display()
{
    struct node *t;
    t=head;
    while(t!=0)
    {
        printf("%d\n",t->d);
        t=t->adr;
    }
}
int main()
{
    head=0;
    int ch=1;
     while(ch==1)
    {
        int c,n;
        printf("1)Enqueue.\n2)Dequeue.\n3)isEmpty.\n4)Peek.\n5)Display.\n6)Clear the screen.\n7)Exit.\n\n\n");
        printf("Enter choice: ");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("Enter data:");
            scanf("%d",&n);
            enqueue(n);
            break;
        case 2:
            if(isEmpty())
                printf("Queue underflow..\n");
            else
            {
                printf("%d\n",head->d);
                dequeue();
            }
            break;
        case 3:
            if(isEmpty())
                printf("Queue underflow..\n");
            else
                printf("Queue not empty..\n");
            break;
        case 5:
            if(isEmpty())
                printf("Queue underflow..\n");
            else
                display();
            break;
        case 4:
            if(isEmpty())
                printf("Queue underflow..\n");
            else
                printf("%d\n",peek());
            break;
        case 6:
            system("cls");
            break;
        case 7:
            printf("Exiting..\n");
            ch=0;
            break;
        default:
            printf("Wrong message..\n");
            break;
        }
}
return 0;
}
