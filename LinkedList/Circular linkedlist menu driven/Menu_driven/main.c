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
        t=head->adr;
        free(head);
        head=t;
    }
}
void del_e()
{
    struct node *t,*a;
    int trav=1;
    t=head;
    while(trav<(count+1))
    {
        if(trav==count-1)
        {  // printf("%d\n",t->d);
            temp=t;
            a=t->adr;
            t->adr=head;
            free(a);
            break;
        }
        t=t->adr;
        trav++;
    }
}
void del_a(int pos)
{ //printf("%d\n",count);
    struct node *t,*a,*b;int trav=1;
    t=head;
    while(trav!=(count+1))
    {
        if(trav==pos-1)
        {
            a=t;
           // printf("%d\n",a->d);
        }
        else if(trav==pos)
        {
            b=t->adr;
           // printf("%d\n",b->d);
            a->adr=b;
            //printf("%d\n",a->d);
            free(t);
            //printf("%d\n",count);
            break;
        }
        t=t->adr;
        trav++;
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
        //printf("%d\n",temp->d);
        temp=newnode;
    }
}
void insert_a(int pos)
{
    struct node *t,*a;int trav=1;
    t=head;
    while(trav<(count+1))
    {
        if(trav==pos-1)
        {
            a=t->adr;
           // printf("%d\n",t->adr);//next old node
            t->adr=newnode;
            //printf("%d\n",t->adr);//next newnode
            break;
        }
        t=t->adr;
        trav++;
    }
    newnode->adr=a;//next old node

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
void dis_e()
{
    struct node *t;int trav=1;
    t=head;
    while(trav!=(count+1))
    {
        if(trav%2==0)
            printf("%d\n",t->d);
        t=t->adr;
        trav++;
    }
}
void dis_o()
{
    struct node *t;int trav=1;
    t=head;
    while(trav!=(count+1))
    {
        if(trav%2!=0)
            printf("%d\n",t->d);
        t=t->adr;
        trav++;
    }
}
void rev()
{
    struct node *t,*a,*b;int trav=1;
    t=head;
    while(trav!=(count+1))
    {
        if(trav==1)
        {
            a=t->adr;
            b=t;
            head=temp;
            temp=t;
            t->adr=head;
        }
        else
        {
            a=t->adr;
            t->adr=b;
            b=t;
        }
        t=a;
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
        printf("1)Insert at the beginning.\n2)Insert at the end.\n3)Insert at any position.\n4)Delete at the beginning.\n5)Delete at the end.\n6)Delete at any position.\n7)Display even nodes.\n8)Display odd nodes.\n9)Reverse the nodes.\n10)Swapping the nodes.\n11)Display the nodes.\n12)Display the total number of nodes.\n13)Clear the console.\n14)Exit.\n\n\n");
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
        case 3:
            printf("Enter position: ");
            scanf("%d",&pos);
           while(pos>(count+1) || pos <1)
           {
               printf("Invalid position..enter correct position: ");
               scanf("%d",&pos);
           }
           newnode=(struct node*)malloc(sizeof(struct node));
           //printf("%d\n",newnode);
           printf("Enter data:");
           scanf("%d",&newnode->d);
           if(pos==1)
           {
            insert_b();
            count++;
           }
           else if(pos==(count+1))
            {
                insert_e();
                count++;
           }
           else
           {
                insert_a(pos);
                count++;
           }
            break;
        case 4:
            if(head==0)
                printf("Empty list..\n");
            else
            {
                del_b();
                count--;
                printf("Node deleted..\n");
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
                    count--;
                    printf("Node deleted..\n");
                }
                else
                {
                    del_e();
                    count--;
                    printf("Node deleted..\n");
                }
            }
            break;
        case 6:
            if(head==0)
                printf("Empty list..\n");
            else
            {
                printf("Enter pos: ");
                scanf("%d",&pos);
                while(pos>count || pos <1)
                {
                    printf("Invalid position...enter correct position: ");
                    scanf("%d",&pos);
                }
                if(pos==1)
                    del_b();
                else if(pos==count)
                    del_e();
                else
                    del_a(pos);
                count--;
                printf("Node deleted..\n");
            }
            break;
        case 7:
            if(head==0)
                printf("Empty list..\n");
            else
            {
                printf("The even nodes are:\n");
                dis_e();
            }
            break;
        case 8:
            if(head==0)
                printf("Empty list..\n");
            else
            {
                printf("The odd nodes are:\n");
                dis_o();
            }
            break;
        case 9:
            if(head==0)
                printf("Empty list..\n");
            else
            {
                rev();
                printf("The nodes are reversed..\n");
            }
            break;

       case 10:
            if(head==0)
                printf("Empty list..\n");
            else if(count<2)
                printf("Swapping cannot occur when less than 2 nodes are present..\n");
            else
            {
                printf("Enter the positions in ascending order: ");
                scanf("%d%d",&pos,&pos2);
                while(pos<1 || pos2<1 || pos>count || pos2 >count || pos>pos2)
                {
                    printf("One of the positions or both the positions might be invalid...please enter the correct positions in ascending order: ");
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
