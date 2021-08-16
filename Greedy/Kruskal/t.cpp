#include <iostream>
#include<vector>
using namespace std;
void dis(vector<vector<int>>v)
{
    cout<<v[2][0]<<endl;
}
int main()
{
    vector<vector<int>> v(3);
    v[2].push_back(1);
    cout<<v[0].size()<<endl;
    dis(v);
}