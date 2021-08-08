#include <iostream>
using namespace std;
struct node
{
    int d;
    struct node *adr;
};
struct node *head, *newnode, *temp;
int count = 0;
bool isEmpty()
{
    if (head == 0)
        return true;
    else
        return false;
}
void enqueue(int x)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->d = x;
    newnode->adr = 0;
    if (isEmpty())
        head = newnode;
    else
        temp->adr = newnode;
    temp = newnode;
    count++;
}
void dequeue()
{
    if (count < 2)
    {
        free(head);
        head = 0;
    }
    else
    {
        struct node *t;
        t = head->adr;
        free(head);
        head = t;
    }
    count--;
}
void ince_str(string s)
{
    for(int i=0;i<s.length();i++)
        enqueue(s[i]);
    //cout<<count<<endl;
    int c = 0;
    while (!isEmpty())
    {
        int t=head->d;
        dequeue();
        if(count==1)
        {
            if(t<head->d)
            {
                if(c==0)
                    cout<<++c<<" "<<++c<<endl;
                else
                    cout<<++c<<endl;
            }
            else
                cout<<1<<endl;
            break;
        }
        else if(t<head->d)
        {
            if(c==0)
                cout<<++c<<" "<<++c<<" ";
            else
                cout<<++c<<" ";
        }
        else
            c=0;
    }
}
void test_case(int n)
{
    while(n>0)
    {  int l;
        string s;
        cin>>l;
        cin>>s;
        ince_str(s);
        n--;
    }
}
int main()
{
    int test;
    cin>>test;
    test_case(test);
    return 0;
}