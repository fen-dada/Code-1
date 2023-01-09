#include<iostream>
using namespace std;
int f[35][500];
int n,m;

int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        int w,v;
        cin>>w>>v;
        for(int j=1;j<=m;j++)
        {
            if(j>=w) f[i][j]=max(f[i-1][j],f[i][j-w]+v);
            else f[i][j]=f[i-1][j];
        }
    }
    cout<<"max="<<f[n][m]<<endl;
}