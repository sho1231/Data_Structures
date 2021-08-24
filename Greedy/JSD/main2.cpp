#include <iostream>
#include <vector>
using namespace std;
int num, slot;
vector<int> arr;
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
void find_max()
{
    sort();
    slot = arr2[0].d;
    for (int i = 1; i < num; i++)
    {
        if (slot < arr2[i].d)
            slot=arr2[i].d;
    }
    slot++;
}
void jsd()
{
    find_max();
    int t_p=0;
    for(int i=0;i<slot;i++)
        arr.push_back(-1);
    int index=0;
    cout<<"Job id:\tProfit:\tDeadline:"<<endl;
    while(index<num)
    {
        if(empty_index(arr2[index].d))
        {
            cout<<arr2[index].id<<"\t"<<arr2[index].p<<"\t"<<(arr2[index].d)+1<<endl;
            if(arr2[index].d>=slot-1)
                arr[slot-1]=arr2[index].p;
            else
                arr[arr2[index].d]=arr2[index].p;
            t_p+=arr2[index].p;
        }
        else
        {   int t=arr2[index].d;
            while(t>=0)
            {
                t--;
                if(empty_index(t))
                {
                    arr[t]=arr2[index].p;
                    cout<<arr2[index].id<<"\t"<<arr2[index].p<<"\t"<<(arr2[index].d)+1<<endl;
                    t_p+=arr2[index].p;
                    break;
                }
            }
        }
        index++;
    }
    cout<<"\nTotal profit="<<t_p;
}
int main()
{
    cout << "Enter the number of jobs:";
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int temp_d;
        cout << "Enter job id,profit and deadline respectively:";
        cin >> in.id >> in.p >> temp_d;
        in.d = temp_d - 1;
        arr2.push_back(in);
    }
    cout<<endl<<endl;
    jsd();
}