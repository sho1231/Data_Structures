#include <iostream>
#include <vector>
using namespace std;
struct o
{
    string name;
    float p, w, r;
};
struct o obj;
vector<o> arr;
float cap;
int num;
void input();
void sort();
void knapsack();
void display();
int main()
{
    //input();
    knapsack();
}
void display()
{
    for (int i = 0; i < num; i++)
    {
        cout << arr[i].name << " " << arr[i].p << " " << arr[i].w << endl;
    }
}
void input()
{
    cout << "Enter the capacity and number of objects:";
    cin >> cap >> num;
    for (int i = 0; i < num; i++)
    {
        cout << "Enter object name,profit and weight respectively:";
        cin >> obj.name >> obj.p >> obj.w;
        obj.r = obj.p / obj.w;
        arr.push_back(obj);
    }
    sort();
    //display();
}
void sort()
{
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (arr[j].r > arr[j + 1].r)
            {
                struct o temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void knapsack()
{
    input();
    cout << endl;
    int size = num - 1;
    float rem_w = cap;
    float profit = 0;
    float temp = 0;
    cout << "Name:\t"
         << "Profit:\t"
         << "Weight:" << endl;
    while (rem_w > 0)
    {
        rem_w -= arr[size].w;
        if (rem_w < 0)
        {
            float temp_w = arr[size].w;
            arr[size].w = temp;
            arr[size].p = (arr[size].w / temp_w) * arr[size].p;
            cout << arr[size].name << "\t " << arr[size].p << "\t " << arr[size].w << endl;
            profit += arr[size].p;
            break;
        }
        cout << arr[size].name << "\t " << arr[size].p << "\t " << arr[size].w << endl;
        temp = rem_w;
        profit += arr[size].p;
        size--;
    }
    cout << endl;
    cout << "Total maximum profit=" << profit;
}