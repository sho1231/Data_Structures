#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
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
void del_b()
{
    if(count<2)
    {
        free(head);
        head=0;
    }
else
    {
    struct node *t;
    t=head;
    head=head->next;
    head->prev=0;
    free(t);
}
}
void del_e()
{
    struct node *t;
    t=temp->prev;
    free(temp);
    temp=t;
    t->next=0;
}
void del_a(int pos)
{
    int trav=1;
    struct node *t,*a,*b;
    t=head;
    while(t!=0)
    {
        if(trav==pos-1)
            a=t;
        else if(trav==pos+1)
        {
            b=t->prev;
            free(b);
            t->prev=a;
            a->next=t;
            break;
        }
        t=t->next;
        trav++;
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
void rev()
{
    struct node *t,*t1,*a;int trav=1;
    t=head;
    while(t!=0)
    {
        if(trav==1)
        {
            t1=t->next;
            t->next=0;
            t->prev=t1;
        }
        else if(trav<count)
        {
            t1=t->next;
            t->next=a;
            t->prev=t1;
        }
        else
        {
            t->prev=0;
            t->next=a;
            head=t;
            break;
        }
        a=t;
        t=t1;
        trav++;
    }
}
void swap(int pos1,int pos2)
{
    struct node *t,*t1;int a,trav=1;
    t=head;
    while(t!=0)
    {
        if(trav==pos1)
        {
            a=t->d;
            t1=t;
        }
        else if(trav==pos2)
        {
            t1->d=t->d;
            t->d=a;
            break;
        }
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
    { printf("1)Insert at the beginning.\n2)Insert at the end.\n3)Insert at any position.\n4)Delete at the beginning.\n5)Delete at the end.\n6)Delete at any position.\n7)Display even nodes.\n8)Display odd nodes.\n9)Reversing the nodes.\n10)Display.\n11)Swapping nodes.\n13)Exit.\n14)Clear the console.\n");
        int c,pos,pos2;
        printf("Enter choice:");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            newnode=(struct node*)malloc(sizeof(struct node));
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
             while(pos>(count+1)|| pos<1)
            {
               printf("Invalid position..please enter correct position: ");
               scanf("%d",&pos);
            }
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
            break;
        case 4:
            if(head==0 || count==0)
                printf("Empty list..\n");
            else
            {   del_b();
                printf("Node deleted...\n");
                count--;
            }
            break;
        case 5:
            if(head==0)
                printf("Empty list..\n");
            else
            {
                if(count<2)
                {
                    del_b();
                    printf("Node deleted...\n");
                }
                else
                {
                    del_e();
                    printf("Node deleted...\n");
                }
                count--;
            }
            break;
        case 6:
            if(head==0)
                printf("Empty list..\n");
            else
            {
                printf("Enter pos: ");
                scanf("%d",&pos);
                 while(pos>(count+1)|| pos<1)
            {
               printf("Invalid position..please enter correct position: ");
               scanf("%d",&pos);
            }
            if(pos==1)
            {
             del_b();
             printf("Node deleted...\n");
            }
            else if(pos==count)
            {
                del_e();
                printf("Node deleted...\n");
            }
            else
            {
                del_a(pos);
                printf("Node deleted...\n");
            }
            count--;
            }
            break;
        case 7:
            if(head==0)
                printf("Empty list..\n");
            else if(count<2)
                printf("No even nodes present..\n");
            else
                dis_e();
            break;
        case 8:
            if(head==0)
                printf("Empty list..\n");
            else
                dis_o();
            break;
        case 9:
            if(head==0)
                printf("Empty list..\n");
            else
            {
                if(count<2)
                    printf("Can't perform reverse operation on less than 2 nodes..\n");
                else
                {
                    rev();
                    printf("Nodes reversed..\n");
                }
            }
            break;
       case 10:
            if(head==0)
                printf("Empty list..\n");
            else
                display();
            break;
        case 11:
            if(head==0)
                printf("Empty list...\n");
            else if(count<2)
                printf("Swapping cannot occur when less than 2 nodes are present..\n");
            else
            {
                printf("Enter the two positions: ");
                scanf("%d%d",&pos,&pos2);
                while(pos<1 || pos2<1 ||pos>count||pos2>count)
                {
                    printf("The position you entered might be invalid..please enter correct positions: ");
                    scanf("%d%d",&pos,&pos2);
                }
                swap(pos,pos2);
                printf("Nodes swapping completed..\n");
            }
            break;
        case 12:
            if(head==0)
                printf("Total number of nodes present are:0");
            else
                printf("Total number of nodes present are:%d",count);
            break;
        case 13:
            d=0;
            printf("Thank you..\n");
            break;
        case 14:
            system("cls");
            break;
        default:
            printf("Wrong choice...\n");
            break;
        }
    }
    return 0;

}
