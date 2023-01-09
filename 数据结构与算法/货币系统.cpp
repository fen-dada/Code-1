#include<iostream>
using namespace std;
const int N=5010;
long long f[N][N]={1};
int n,m;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int v;
        cin>>v;
        f[i][0]=1;
        for(int j=1;j<=m;j++)
        {
            if(j>=v) f[i][j]=f[i-1][j]+f[i][j-v];
            else f[i][j]=f[i-1][j];
        }
    }
    cout<<f[n][m]<<endl;
}