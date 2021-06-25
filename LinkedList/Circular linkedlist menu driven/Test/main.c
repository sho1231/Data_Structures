#include <stdio.h>
#include <stdlib.h>
struct node
{
    int d;
    struct node *adr;
};
struct node *head,*newnode,*temp;
int count=0;
void insert_b()
{
    if(head==0)
    {
        head=temp=newnode;
        newnode->adr=head;
    }
    else
    {
        newnode->adr=head;
        head=newnode;
    }
}
void insert_e()
{
    newnode->adr=head;
    if(head==0)
        head=temp=newnode;
    else
    {
        temp->adr=newnode;
        temp=newnode;
    }
}
void swap(int pos1,int pos2)
{
    struct node *t,*t1;int a,trav=1;
    t=head;
    while(trav!=(count+1))
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
        t=t->adr;
        trav++;
    }
}
void display()
{
    struct node *t;int trav=count;
    t=head;
    while(trav!=0)
    {
        printf("%d\n",t->d);
        t=t->adr;
        trav--;
    }
}
int main()
{   head=0;
    int ch=1;
    while(ch==1)
    {
        printf("1)Insert at the beginning.\n2)Insert at the end.\n10)Swapping the nodes.\n11)Display the nodes.\n12)Display the total number of nodes.\n13)Clear the console.\n14)Exit.\n\n\n");
        int c,pos,pos2;
        printf("Enter choice: ");
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
        case 10:
            if(head==0)
                printf("Empty list..\n");
            else if(count<2)
                printf("Swapping cannot occur when less than 2 nodes are present..\n");
            else
            {
                printf("Enter the positions: ");
                scanf("%d%d",&pos,&pos2);
                while(pos<1 || pos2<1 || pos>count || pos2 >count)
                {
                    printf("One of the positions or both the positions might be invalid...please enter the correct positions: ");
                    scanf("%d%d",&pos,&pos2);
                }
                swap(pos,pos2);
                printf("Nodes are swapped..\n");
            }
            break;
        case 11:
            if(head==0)
                printf("Empty list..\n");
            else
            {
                printf("Displaying nodes...\n");
                display();
            }
            break;
        case 12:
            if(head==0)
                printf("Empty list..\n");
            else
                printf("Total number of nodes: %d\n",count);
            break;
        case 13:
            system("cls");
            break;
        case 14:
            printf("Thank you..\n");
            ch=0;
            break;
        default:
            printf("Wrong choice..\n");
            break;
        }
    }
    return 0;
}
