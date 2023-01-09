#include<iostream>
using namespace std;
const int N=110;
int a[N][N],f[N][N];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    f[1][1]=a[1][1];//后续便利要么便利不到1、1，要么重复便利1、1
    for(int i=2;i<=n;i++)
    {
        f[1][i]+=a[1][i]+f[1][i-1];
    }
    for(int j=2;j<=n;j++)//因为要找最小值，而出街的区域正好是0，所以先把前缀和算好
    {
        f[j][1]+=a[j][1]+f[j-1][1];//或者把外面设置为无穷大，但是丑陋了一点
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=n;j++)
        {
            f[i][j]=min(f[i-1][j],f[i][j-1])+a[i][j];
        }
    }
    cout<<f[n][n];
}