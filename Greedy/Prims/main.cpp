#include <iostream>
#include <vector>
using namespace std;
int inf=9999;
struct Gra
{
    int v;
    vector<vector<int>>arr;
};
struct Gra g;
struct que
{
    int key,p;
};
struct que q;
vector<que> arr1;
vector<int> check;
int temp;
void rem_pa();
bool empty();
int min();
void prims(int v);
void display();
int main()
{
    FILE *fp;
    fp = fopen("t.txt", "r");
    if (fp == NULL)
    {
        printf("\nError to open the file\n");
        exit(1);
    }
    fscanf(fp, "%d", &g.v);
    for(int i=0;i<g.v;i++)
    {
        vector<int> temp;
        for(int j=0;j<g.v;j++)
        {
            int t;
            fscanf(fp, "%d", &t);
            if(i==j&&t>0)
                t=0;
            temp.push_back(t);
        }
        g.arr.push_back(temp);
    }
    for(int i=0;i<g.v;i++)
    {
      q.key=inf;
      q.p=-1;
      arr1.push_back(q);
    }
    //cout<<empty();
     temp=0;
    prims(0);
}
void rem_pa()
{
    for(int i=0;i<g.v;i++)
    {
        for(int j=0;j<g.v;j++)
        {
            if(g.arr[i][j]<g.arr[j][i])
                g.arr[j][i]=g.arr[i][j];
            else if(g.arr[i][j]>g.arr[j][i])
                g.arr[i][j]=g.arr[j][i];
        }
    }
}
bool empty()
{
    int count=0;
    for(int i=0;i<g.v;i++)
    {
       if(arr1[i].key==-1)
            count++;
    }
    if(count==g.v)
        return true;
    else
        return false;
}
int min()
{
    int t;
    for(int i=0;i<g.v;i++)
    {
        if(arr1[i].key!=-1)
            int t=i;
    }
    for(int i=0;i<g.v;i++)
    {
        if(arr1[i].key!=-1&&arr1[i].key!=inf&&arr1[i].key<arr1[t].key)
            t=i;
    }
    return t;
}
void prims(int v)
{
    // cout<<"Enter";
    // int check=empty();
    // cout<<check;
    while(!empty())
    {
        arr1[v].key=-1;
        for(int i=0;i<g.v;i++)
        {
            if(arr1[i].key!=-1&&g.arr[v][i]!=0&&g.arr[v][i]!=inf)
            {
                if(g.arr[v][i]<arr1[i].key)
                {
                    arr1[i].key=g.arr[v][i];
                    arr1[i].p=v;
                }
            }   
        }
        //cout<<v<<" ";
        v=min();
    }
    display();
}
void display()
{
    int edges=0;
    int sum=0;
    for(int i=0;i<arr1.size();i++)
    {
        if(i!=temp)
        {
            cout<<"Edges "<<++edges<<" ";
            int parent=arr1[i].p;
            int child=i;
            cout<<"From "<<parent<<" to "<<child<<": weight=";
            cout<<g.arr[parent][child]<<endl;
            sum+=g.arr[parent][child];
        }
    }
    cout<<"Cost of MST="<<sum;
}