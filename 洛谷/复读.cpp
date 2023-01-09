#include<iostream>
using namespace std;
const int N=520;
int main()
{
    string a[N]={"0"};
    string t;
    bool is_find;
    int index=1;
    while(cin>>t)
    {
        if(t=="0") break;
        for(int i=1;a[i]!="0";i++)
        {
            if(a[i]==t) is_find=true;
        }
        if(!is_find) 
        {
            cout<<t;
            a[index++]=t;
        }
    }
}