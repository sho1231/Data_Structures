#include <iostream>
#include <vector>
#include <stdbool.h>
using namespace std;
vector<int> arr;
int slot, num;
struct info
{
    string id;
    float p;
    int d;
};
struct info in;
vector<info> arr2;
bool empty_index(int a)
{
    if (arr[a] == -1)
        return true;
    else
        return false;
}
bool empty_slot()
{
    int count=0;
    for(int i=0;i<slot;i++)
    {
        if(arr[i]!=-1)
            count++;
    }
    if(count==slot)
        return false;
    else
        return true;
}
void sort()
{
    for (int i = 0; i < arr2.size() - 1; i++)
    {
        for (int j = 0; j < arr2.size() - i - 1; j++)
        {
            if (arr2[j].p < arr2[j + 1].p)
            {
                struct info temp = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = temp;
            }
        }
    }
}
void jsd()
{
    sort();
    for(int i=0;i<slot;i++)
        arr.push_back(-1);
    int index=0;
    while(empty_slot())
    {
        if(empty_index(arr2[index].d))
        {
            if(arr2[index].d>=slot-1)
                arr[slot-1]=arr2[index].p;
            else
                arr[arr2[index].d]=arr2[index].p;
        }
        else
        {   int t=arr2[index].d;
            while(!empty_index(t))
            {
                t--;
                if(empty_index(t))
                {
                    arr[t]=arr2[index].p;
                    break;
                }
            }
        }
        index++;
    }
}
void display()
{
    jsd();
    for(int i=0;i<slot;i++)
        cout<<arr[i]<<" ";
}
int main()
{
    cout << "Enter how many slots are empty:";
    cin >> slot;
    cout<<"Enter the number of jobs:";
    cin>>num;
    for (int i = 0; i < num; i++)
    {
        cout << "Enter job id,profit and deadline respectively:";
        cin >> in.id >> in.p >> in.d;
        arr2.push_back(in);
    }
    display();
}