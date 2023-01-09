#include<iostream>
using namespace std;
const int INF=0x3f3f;
int a[1000000]={0};
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int cnt=0;
        string str;
        cin>>str;
        for(int i=0;i<str.length();i++)
        {
            a[(int)str[i]]++;
        }
        int num=INF;
        for(int i=97;i<=130;i++)
        {
            if(a[i]) num=min(num,a[i]);
        }
        for(int i=97;i<=130;i++)
        {
            if(a[i]) cnt+=a[i]/num;
        }
        cout<<cnt<<endl;
    }
}