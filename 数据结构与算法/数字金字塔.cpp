#include<iostream>
using namespace std;
const int N=1010,INF=0x3f3f3f3f;
int a[N][N],f[N][N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin>>a[i][j];
        }
    }
    f[1][1]=a[1][1];
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)//j不能从2开始，因为会漏掉第二行第一个
        {
            f[i][j]=max(f[i-1][j],f[i-1][j-1])+a[i][j];
        }
    }
    int ans=-INF;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,f[n][i]);
    }
    cout<<ans<<endl;
}