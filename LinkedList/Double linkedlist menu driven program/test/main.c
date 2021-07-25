#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int d;
    struct node *next;
};
struct node *head,*newnode,*temp;
int count=0;
void insert_b()
{
    newnode->next=0;
    if(head==0)
    {
        head=temp=newnode;
        head->prev=0;
    }
    else
    {
      newnode->prev=0;
      newnode->next=head;
      head->prev=newnode;
      head=newnode;
    }
}
void insert_e()
{
    newnode->next=0;
    if(head==0)
    {
        head=temp=newnode;
        newnode->prev=0;
    }
    else
    {
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
    }
}
void insert_a(int pos)
{
    int trav=1;
    struct node *t;
    t=head;
    while(t!=0)
    {
        if(trav==(pos-1))
        {
            newnode->prev=t;
        }
        else if(trav==pos)
        {  newnode->next=t;
            t->prev=newnode;
            t=newnode->prev;
            t->next=newnode;
            break;
        }
        trav++;
        t=t->next;
    }

}
void dis_o()
{
    struct node *t;int trav=1;
    t=head;
    while(t!=0)
    {   if(trav%2!=0)
        printf("%d\n",t->d);
        t=t->next;
        trav++;
    }
}
void dis_e()
{
    struct node *t;int trav=1;
    t=head;
    while(t!=0)
    {   if(trav%2==0)
        printf("%d\n",t->d);
        t=t->next;
        trav++;
    }
}
void display()
{
    struct node *t;
    t=head;
    while(t!=0)
    {
        printf("%d\n",t->d);
        t=t->next;
    }
}
int main()
{
    head=0;
    int d=1;
    while(d==1)
    { printf("1)Insert at the beginning.\n2)Insert at the end.\n3)Insert at any position.\n10)Display.\n12)Exit.\n");
        int c,pos;
        printf("Enter choice:");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            newnode=newnode=(struct node*)malloc(sizeof(struct node));
            count++;
            printf("Enter data: ");
            scanf("%d",&newnode->d);
            insert_b();
            break;
        case 2:
            newnode=(struct node*)malloc(sizeof(struct node));
            count++;
            printf("Enter data: ");
            scanf("%d",&newnode->d);
            insert_e();
            break;
        case 3:
            printf("Enter position: ");
            scanf("%d",&pos);
            if(pos==1)
            {   newnode=(struct node*)malloc(sizeof(struct node));
                count++;
                printf("Enter data: ");
                scanf("%d",&newnode->d);
                insert_b();
            }
            else if(pos==(count+1))
            {
                newnode=(struct node*)malloc(sizeof(struct node));
                count++;
                printf("Enter data: ");
                scanf("%d",&newnode->d);
                insert_e();
            }
            else if(pos>=1 && pos<=count)
            {
                newnode=(struct node*)malloc(sizeof(struct node));
                count++;
                printf("Enter data: ");
                scanf("%d",&newnode->d);
                insert_a(pos);
            }
            else
                printf("Invalid position..\n");
            break;
        case 4:
            if(head==0)
                printf("Empty list..\n");
            else
                dis_o();
            break;
        case 5:
            if(head==0)
                printf("Empty list..\n");
            else if(count<2)
                printf("No even nodes present..\n");
            else
                dis_e();
            break;
       case 10:
            if(head==0)
                printf("Empty list..\n");
            else
                display();
                break;
        case 12:
            d=0;
            printf("Thank you..\n");
            break;
        default:
            printf("Wrong choice...\n");
            break;
        }
    }
    return 0;

}
