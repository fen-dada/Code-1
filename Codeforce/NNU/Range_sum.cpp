#include<iostream>
using namespace std;
const int N=100000000;
int a[N];
int s[N];
int main()
{
    int n;
    int t;
    int ans=0;
    cin>>n>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    s[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(s[j]-s[i-1]<t) ans++;
        }
    }
    cout<<ans;
}