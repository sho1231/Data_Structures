#include <iostream>

using namespace std;
void increasing(string s)
{  string st="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>s[i+1])
        {
            for(int j=0;j<=st.length();j++
                cout<<(j+1)<<" ";
            st.erase(0);
        }
        else
        {
            st.append(s[i]);
            st.append(s[i+1]);
        }
    }
}
int main()
{

}