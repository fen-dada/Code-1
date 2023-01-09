#include<iostream>
using namespace std;
const int N=1010;
int f[N][N];
int n,m;

int main()
{
    f[0][0]=1;//初始化边界
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int v;
        cin>>v;
        f[i][0]=1;
        for(int j=1;j<=m;j++)
        {
            if(j>=v) f[i][j]=f[i-1][j]+f[i-1][j-v];
            else f[i][j]=f[i-1][j];
            //f[i][j]=f[i-1][j]+f[i-1][j-v]*(j>=v);
        }
    }
    cout<<f[n][m]<<endl;
}