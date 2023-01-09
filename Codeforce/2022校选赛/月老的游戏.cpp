#include<iostream>
#include<cmath>
using namespace std;
long long sum=0;
int cnt=0;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        sum=0;
        cnt=0;
        int len;
        cin>>len;
        bool a[100];
        string str;
        cin>>str;
        for(int i=len;i>=1;i--)
        {
            a[i]=str[i-1]-'0';
        }
        for(int i=1;i<=len;i++)
        {
            if(a[i]) cnt++;
        }
        for(int i=1;i<=cnt;i++)
        {
            sum+=pow(2,i-1);
        }
        cout<<sum<<endl;
    }
}