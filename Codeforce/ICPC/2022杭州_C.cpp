#include<iostream>
using namespace std;
const int N=10000;
typedef long long ll;
ll a[N][N];
ll f[N];
int n,k;
ll mar=0;

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i][0]);
        for(int j=1;j<=a[i][0];j++)
        {
            scanf("%lld",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=k;j>=0;j--)
        {
            if(j>=a[i][0] && f[j]<f[j-a[i][0]]+a[i][a[i][0]]) f[j]=f[j-a[i][0]]+a[i][a[i][0]];
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     int t=k-1;
    //     if(t<0)
    //     {
    //         mar=0;
    //         break;
    //     }
    //     while(f[t]==f[k]&&!book[i])
    //     {
    //         mar=max(mar,a[i][k-t]);
    //         t--;
    //         cout<<mar<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<f[k];
}