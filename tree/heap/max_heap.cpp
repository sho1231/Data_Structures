#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
void insert(int d)
{
    if (arr.size() == 0)
    {
        arr.push_back(d);
    }
    else
    {
        arr.push_back(d);
        int i = arr.size() - 1;
        while (arr[(i - 1) / 2] < d)
        {
            arr[i] = arr[(i - 1) / 2];
            i = (i - 1) / 2;
            if (i == 0)
                break;
        }
        arr[i] = d;
    }
}
int check(int pos)
{
    int left = (2 * pos) + 1;
    int right = (2 * pos) + 2;
    if (left >= arr.size() || right >= arr.size())
        return -1;
    if (arr[left] < arr[right])
        return right;
    else
        return left;
}
void del()
{
    //cout<<pos<<endl;
    int te = arr[arr.size() - 1];
    //cout<<te<<endl;
    arr[0] = te;
    int pos2 = check(0);
    //cout<<pos2<<endl;
    while (te < arr[pos2])
    {
        if (pos2 == -1)
            break;
        arr[(pos2 - 1) / 2] = arr[pos2];
        arr[pos2] = te;
        pos2 = check(pos2);
    }
    arr.erase(arr.begin() + (arr.size() - 1));
    // arr[(pos2-1)/2]=te;
    // cout<<pos2<<endl;
}
void display()
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}
int main()
{
    int n = 1;
    while (n == 1)
    {
        cout << "1)Insert element.2)Delete element.3)Display.4)Exit." << endl;
        int x;
        cout << "Enter choice:";
        cin >> x;
        switch (x)
        {
            int y;
        case 1:

            cout << "Enter your element:";
            cin >> y;
            insert(y);
            break;
        case 2:
            //int y;
            // cout<<"Enter your element:";
            //cin>>y;
            del();
            break;
        case 3:
            display();
            cout << endl;
            break;
        case 4:
            n = 0;
            break;
        default:
            cout << "Wrong choice" << endl;
        }
    }
    return 0;
}