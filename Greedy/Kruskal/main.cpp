#include <iostream>
#include <vector>
#include<stdbool.h>
using namespace std;
int inf = 9999;
struct Gra
{
    int v;
    vector<vector<int>> arr;
};
struct Gra g;
struct set
{
    int u, v, c;
};
struct set s;
vector<set> arr1;
struct ver
{
    int p, r;
};
struct ver v;
vector<ver> arr2;
//void display(vector<vector<int>> ve);
void sort();
bool isCyclic(int a,int b);
int find(int v);
void remove_par();
void uni(int a,int b);
void kruskal();
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
    for (int i = 0; i < g.v; i++)
    {
        vector<int> temp;
        for (int j = 0; j < g.v; j++)
        {
            int t;
            fscanf(fp, "%d", &t);
            if(i==j&&t>0)
                t=0;
            temp.push_back(t);
            if (t != 0 && t != inf)
            {
                s.u = i;
                s.v = j;
                s.c = t;
                arr1.push_back(s);
            }
        }
        g.arr.push_back(temp);
    }
    arr2.resize(g.v);
    for(int i=-0;i<g.v;i++)
   {
       arr2[i].p=-1;
       arr2[i].r=0;
   }
   kruskal();

}
void sort()
{
    for (int i = 0; i < arr1.size() - 1; i++)
    {
        for (int j = 0; j < arr1.size() - i - 1; j++)
        {
            if (arr1[j].c > arr1[j + 1].c)
            {
                struct set t;
                t = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = t;
            }
        }
    }
}
int find(int v)
{
    if(arr2[v].p==-1)
        return v;
    return arr2[v].p=find(arr2[v].p);
}
void uni(int a,int b)
{
    if(arr2[a].r>arr2[b].r)
        arr2[b].p==a;
    else if(arr2[a].r<arr2[b].r)
        arr2[a].p=b;
    else
    {
        arr2[a].p=b;
        arr2[b].r+=1;
    }

}
bool isCylic(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b)
        return true;
    uni(a,b);
    return false;
}
void kruskal()
{  int sum=0;
    int edges=0;
    remove_par();
    sort();
    for(int i=0;i<arr1.size();i+=2)
    {
        if(!isCylic(arr1[i].u,arr1[i].v))
        {
            cout<<"Edge "<<++edges<<":from vertex "<<arr1[i].u<<" to vertex "<<arr1[i].v<<": weight="<<arr1[i].c<<endl;
            sum+=arr1[i].c;
        }
    }
    cout<<"\nTotal weight of minimum spanning tree="<<sum<<endl;
}
void remove_par()
{
    for(int i=0;i<g.v;i++)
    {
        for(int j=0;j<g.v;j++)
        {
            if(g.arr[i][j]<g.arr[j][i])
            {
                for(int k=0;i<arr1.size();i++)
                {
                    if(arr1[k].u==j&&arr1[k].v==i)
                    {
                        arr1[k].c=g.arr[i][j];
                        break;
                    }
                }
            }
            else if(g.arr[i][j]>g.arr[j][i])
            {
                for(int k=0;i<arr1.size();i++)
                {
                    if(arr1[k].v==j&&arr1[k].u==i)
                    {
                        arr1[k].c=g.arr[j][i];
                        break;
                    }
                }
            }
            else
                break;
        }
    }
}