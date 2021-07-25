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
void insert_e()
{ //printf("%d\n",count);
    if(head==0)
        head=temp=newnode;
    else
        temp->next=newnode;
    newnode->next=head;
    newnode->prev=temp;
    temp=newnode;
    count++;
}
void insert_b()
{ //printf("%d\n",count);
    if(head==0)
    {
        head=temp=newnode;
        head->next=head;
        head->prev=temp;
    }
    else
    {
        newnode->next=head;
        newnode->prev=temp;
        head->prev=newnode;
        head=newnode;
    }
    count++;
}
void insert_a(int pos)
{
    int trav=1;
    //printf("%d\n",count);
    struct node *t;
    t=head;
    while(trav<(count+1))
    {
        if(trav==(pos-1))
        {
            newnode->prev=t;
        }
        else if(trav==pos)
        {
            newnode->next=t;
            t->prev=newnode;
            t=newnode->prev;
            t->next=newnode;
            break;
        }
        trav++;
        t=t->next;
    }
    count++;
}
void del_b()
{
   // printf("Entered in the del_b()..\n");
    if(count==1)
    {
        free(head);
        head=0;
    }
    else
    {
    struct node *t;
    t=head->next;
    free(head);
    t->prev=temp;
    head=t;
    temp->next=head;
    }
    count--;
    //printf("%d\n",count);
}
void del_e()
{
   // printf("Entered in the del_e()..\n");
    struct node *t;
    t=temp->prev;
    free(temp);
    t->next=head;
    temp=t;
    head->prev=temp;
    printf("%d\n",temp->d);
    count--;
    //printf("%d\n",count);
}
void del_a(int pos)
{
    //printf("Entered in the del_a()..\n");
    struct node *t,*a,*b;int trav=1;
    t=head;
    while(trav<(count+1))
    {
        if(trav==(pos+1))
        {
           a=t->prev;
           b=a->prev;
           t->prev=b;
           b->next=t;
           free(a);
           break;
        }
      t=t->next;
      trav++;
    }
    count--;
   // printf("%d\n",count);
}
void dis_e()
{
    struct node *t;int trav=1;
    t=head;
    while(trav<(count+1))
    {
        if(trav%2==0)
            printf("%d\n",t->d);
        t=t->next;
        trav++;
    }
}
void dis_o()
{
     struct node *t;int trav=1;
    t=head;
    while(trav<(count+1))
    {
        if(trav%2!=0)
            printf("%d\n",t->d);
        t=t->next;
        trav++;
    }
}
void rev()
{
    struct node *t,*a,*b;int trav=1;
    t=head;
    while(trav<(count+1))
    {
        if(trav==1)
        {
            a=t->next;//a=200;
            t->prev=t->next;
            t->next=temp;
        }
        else if(trav<count)
        {
            a=t->next;//a=400;
            b=t->prev;//b=200;
            t->prev=a;//400
            t->next=b;//200
        }
        else
        {
            a=t->next;//a=100
            temp=a;//100
            b=t->prev;//300
            t->prev=a;//100
            t->next=b;//300
            head=t;
            break;
        }
        t=a;
        trav++;
    }
}
void swap(int pos1,int pos2)
{
    struct node *t,*t1;int a,trav=1;
    t=head;
    while(trav<(count+1))
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
    struct node *t;int trav=1;
    t=head;
    while(trav<(count+1))
    {
        printf("%d\n",t->d);
        t=t->next;
        trav++;
    }
}
int main()
{
    head=0;int ch=1;
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
            printf("Enter data: ");
            scanf("%d",&newnode->d);
            insert_b();
            printf("Node inserted..\n");
            break;
        case 2:
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("Enter data: ");
            scanf("%d",&newnode->d);
            insert_e();
            printf("Node inserted..\n");
            break;
        case 3:
            printf("Enter the position: ");
            scanf("%d",&pos);
            while(pos>(count+1)|| pos<1)
            {
               printf("Invalid position..please enter correct position: ");
               scanf("%d",&pos);
            }
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("Enter data: ");
            scanf("%d",&newnode->d);
             if(pos==1)
                insert_b();
             else if(pos==(count+1))
                insert_e();
             else
                insert_a(pos);
             printf("Node inserted at position %d..\n",pos);
             break;
        case 4:
            if(head==0 || count==0)
                printf("Empty list..\n");
            else
            {   del_b();
                printf("Node deleted...\n");
            }
            break;
         case 5:
            if(head==0)
                printf("Empty list..\n");
            else
            {
                if(count<2)
                    del_b();
                else
                    del_e();
            printf("Node deleted...\n");
            }
            break;
         case 6:
            if(head==0)
                printf("Empty list..\n");
            else
            {
                printf("Enter pos: ");
                scanf("%d",&pos);
                 while(pos>count|| pos<1)
            {
               printf("Invalid position..please enter correct position: ");
               scanf("%d",&pos);
            }
            if(pos==1)
                del_b();
            else if(pos==count)
                del_e();
            else
                del_a(pos);
            printf("Node deleted...\n");
            }
            break;
     case 7:
            if(head==0)
                printf("Empty list..\n");
            else if(count<2)
                printf("No even nodes present..\n");
            else
            {   printf("Displaying even nodes..\n");
                dis_e();
            }
            break;
        case 8:
            if(head==0)
                printf("Empty list..\n");
            else
            {   printf("Displaying odd nodes..\n");
                dis_o();
            }
            break;
        case 9:
            if(head==0)
                printf("Empty list..\n");
            else
            {
                rev();
                printf("Nodes reversed..\n");
            }
            break;
        case 10:
            if(head==0)
                printf("Empty list...\n");
            else if(count<2)
                printf("Swapping cannot occur when less than 2 nodes are present..\n");
            else
            {
                printf("Enter the two positions in ascending order: ");
                scanf("%d%d",&pos,&pos2);
                while(pos<1 || pos2<1 ||pos>count||pos2>count || pos>pos2)
                {
                    printf("The positions you entered might be invalid or not in ascending order..please enter correct positions in ascending order: ");
                    scanf("%d%d",&pos,&pos2);
                }
                swap(pos,pos2);
                printf("Nodes swapping completed..\n");
            }
            break;
     case 11:
            if(head==0)
                printf("Empty list..\n");
            else
            {
                printf("Displaying nodes.\n");
                display();
            }
            break;
        case 12:
            if(head==0)
                printf("Total number of nodes=0\n");
            else
                printf("Total number of nodes=%d\n",count);
            break;
        case 13:
            system("cls");
            break;
        case 14:
            ch=0;
            printf("Thank you..\n");
            break;
        default:
            printf("Wrong choice...\n");
            break;
        }
    }
    return 0;
}
