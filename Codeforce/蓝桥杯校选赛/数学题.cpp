#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char ch;
    int x;
    int sum=0;
    sum+=n;
    while(cin>>ch>>x)
    {
        if(ch=='+') sum+=x;
        if(ch=='-') sum-=x;
        if(ch=='*') sum*=x;
        if(ch=='/') sum/=x;
    }
    cout<<sum;
}