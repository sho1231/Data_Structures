#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    int d;
    struct node *adr;
};
struct node *top,*newnode;
bool isEmpty();
void push()
{
  if(isEmpty())
    newnode->adr=0;
  else
    newnode->adr=top;
  top=newnode;
}
void pop()
{   if(isEmpty())
        printf("Stack Underflow..\n");
    else
    {
    struct node *t;
    t=top->adr;
    free(top);
    top=t;
    }
}
bool isEmpty()
{
    if(top==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void peek()
{
    if(isEmpty())
        printf("Stack underflow..\n");
    else
        printf("%d\n",top->d);
}
void display()
{
    if(isEmpty())
        printf("Stack underflow..\n");
    else
    {
        struct node *t;
        t=top;
        while(t!=0)
        {
            printf("%d\n",t->d);
            t=t->adr;
        }
    }
}
int main()
{
    top=0;
    int ch=1;
    while(ch==1)
    {
        int c;
        printf("1)Push.\n2)Pop.\n3)isEmpty.\n4)Peek.\n5)Display.\n6)Clear the screen.\n7)Exit.\n\n\n");
        printf("Enter choice: ");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("Enter data: ");
            newnode=(struct node*)malloc(sizeof(struct node));
            scanf("%d",&newnode->d);
            push();
            break;
        case 2:
            printf("%d\n",top->d);
            pop();
            break;
        case 3:
            if(isEmpty())
                printf("Stack Underflow..\n");
            else
                printf("Stack not undeflow..\n");
            break;
        case 4:
            peek();
            break;
        case 5:
            display();
            break;
        case 6:
            system("cls");
            break;
        case 7:
            printf("Exiting..\n");
            ch=0;
            break;
        default:
            printf("Wrong choice...\n");
            break;

        }
    }
}
