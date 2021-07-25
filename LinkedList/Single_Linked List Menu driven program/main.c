#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *adr;

};
struct node *head,*newnode,*temp;
int count=0;
void in_b()
{
    if(head==0)
    {   newnode->adr=0;
        head=temp=newnode;
    }
    else
    {
       newnode->adr=head;
       head=newnode;
    }
}
 void in_e()
    { newnode->adr=0;
        if(head==0)
            head=temp=newnode;
        else
        {
            temp->adr=newnode;
            temp=newnode;

        }
    }
 void in_m(int pos)
 {
     struct node *t,*a;
     int trav=1;
     t=head;
     while(t!=0)
    {
        if(trav==(pos-1))
     {
         a=t->adr;
         t->adr=newnode;
         break;
     }
     t=t->adr;
     trav++;

    }
    newnode->adr=a;

 }
 void del_b()
 {
     struct node *t=head;
     head=t->adr;
     free(t);
 }
 void de_a(int pos)
{
    int trav=1;
    struct node *t,*a,*b;
    t=head;
    while(t!=0)
    {
        if(trav==(pos-1))
        {
            a=t->adr;
            b=a->adr;
            t->adr=b;
            free(a);
            break;

        }
        trav++;
        t=t->adr;
    }
}

 void del_e()
 {
     struct node *t;
     int trav=1;
     t=head;
     while(t!=0)
     {
         if(trav==(count-1))
         {
             free(t->adr);
             t->adr=0;
             break;
         }

         trav++;
         t=t->adr;

     }
 }
void d_o()
{
    int odd=1;
    struct node *t;
    t=head;
    while(t!=0)
    {
        if(odd%2!=0)
            printf("%d\n",t->data);
        t=t->adr;
        odd++;
    }
}
void d_e()
{
    int even=1;
    struct node *t;
    t=head;
    while(t!=0)
    {   if(even%2==0)
        {
        printf("%d\n",t->data);
        }
        t=t->adr;
        even++;
    }
}
void rev()
{
    struct node*t,*a,*b;//t=address of next node,a=address of next node,b=address of prev node
    int trav=1;
    t=head;
    while(t!=0)
    {
        if(trav==1)
        {
            a=t->adr;
            t->adr=0;
            b=t;
            t=a;
        }
        else if(trav<count)
        {
            a=t->adr;
            t->adr=b;
            b=t;
            t=a;
        }
        else if(trav==count)
        {
            t->adr=b;
            head=t;
            break;
        }
        trav++;
    }

}
void swap(int pos1,int pos2)
{
    struct node *t,*a;int trav=1,t1,t2;
    t=head;
    while(t!=0)
    {
        if(trav==pos1)
        {
            a=t;
            t1=t->data;
        }
        else if(trav==pos2)
        {
            t2=t->data;
            t->data=t1;
            a->data=t2;
            break;
        }
        trav++;
        t=t->adr;
    }
}

void display()
{ struct node *t;
    t=head;
    while(t!=0)
    {
        printf("%d\n",t->data);
        t=t->adr;
    }
}
int main()
{ head=0;
    int choice=1;
    while(choice==1)
    {
        printf("1)Insert in the begining.\n2)Insert in the end.\n3)Insert in any position.\n4)Delete at the beginning.\n5)Delete at any position.\n6)Delete at the end.\n7)Display even nodes.\n8)Display odd nodes.\n9)Reversing the available nodes.\n10)Display nodes.\n11)Display total number of nodes.\n12)Swapping nodes.\n13)Exit.\n14)Clear the console.\n\n\n");
        int c,pos,pos2;
        printf("Enter choice: ");
        scanf("%d",&c);
        //int n;
        switch(c)
        {
        case 1:
             newnode=(struct node*)malloc(sizeof(struct node));
             count++;
             printf("Enter data: ");
             scanf("%d",&newnode->data);//0
             in_b();
             break;
        case 2:
                newnode=(struct node*)malloc(sizeof(struct node));
                count++;
                printf("Enter data:");
                scanf("%d",&newnode->data);
                in_e();
                break;
        case 3:
           printf("Enter position: ");
           scanf("%d",&pos);
           while(pos>(count+1) || pos <1)
           {
               printf("Invalid position..enter correct position: ");
               scanf("%d",&pos);
           }
           if(pos==1)
           {
             newnode=(struct node*)malloc(sizeof(struct node));
             count++;
             printf("Enter data: ");
             scanf("%d",&newnode->data);
             in_b();
           }
           else if(pos==(count+1))
           {
               newnode=(struct node*)malloc(sizeof(struct node));
               count++;
               printf("Enter data: ");
               scanf("%d",&newnode->data);
               in_e();
           }
           else
           {
            newnode=(struct node*)malloc(sizeof(struct node));
            count++;
             printf("Enter data: ");
             scanf("%d",&newnode->data);
               in_m(pos);
           }
           break;
        case 4:
            if(head==0)
                printf("Empty list..\n");
            else
            {
                del_b();
                printf("Node deleted..\n");
                count--;
            }
            break;
        case 5:
            if(head==0)
                printf("Empty list..\n");
            else
            {
                printf("Enter position: ");
                scanf("%d",&pos);
              while(pos>count|| pos <1)
           {
               printf("Invalid position..enter correct position: ");
               scanf("%d",&pos);
           }

            if(pos==1)
                if(head==0)
                    printf("Empty list..\n");
            else
                {
                 del_b();
                 count--;
                }
            else if(pos==count)
            {
                if(head==0)
                printf("Empty list..\n");
            else
                {
                    del_e();
                    count--;
                }
            }
            else
            {
                de_a(pos);
                printf("Node %d deleted..\n",pos);
                count--;
            }

            }
            break;

        case 6:
            if(head==0)
                printf("Empty list..\n");
            else if(count==1)
            {
                 del_b();
                printf("Node deleted..\n");
                count--;
            }

            else
            {
                del_e();
                printf("Node deleted..\n");
                count--;
            }
            break;
        case 7:
             if(head==0)
                printf("Empty list..\n");
            else if(count<2)
            {
                printf("No even nodes..\n");
            }
            else
                {
                    printf("Displaying even nodes..\n");
                    d_e();
                }
            break;
        case 8:
             if(head==0)
                printf("Empty list..\n");
            else
                {
                    printf("Displaying odd nodes..\n");
                    d_o();
                }
            break;
        case 9:
            if(head==0)
                printf("Empty list..\n");
            else
            {
                if(count==1)
                    printf("Only 1 node is avaliable..no reverse operation can be done..\n");
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
                {
                    printf("Displaying nodes..\n");
                    display();
                }
            break;
        case 11:
            printf("Total number of nodes are: %d\n",count);
            break;
        case 12:
            if(head==0 || count<2)
                printf("Swapping can only occur when more than 1 node is present..\n");
            else
            {
                 printf("Enter the two positions: ");
                scanf("%d%d",&pos,&pos2);
                while(pos<1 || pos2<1 || pos>count || pos2>count || pos>pos2)
                {
                printf("The positions you entered is invalid or not in ascending order,please enter correct positions in ascending order: ");
               scanf("%d%d",&pos,&pos2);
                }
                swap(pos,pos2);
                printf("Nodes swapped..\n");
            }
            break;
        case 13:
            printf("Thank you..\n\n");
            choice=0;
            break;
        case 14:
            system("cls");
            break;
        default:
            printf("Wrong choice..\n");
            break;
        }
    }

    return 0;
}
