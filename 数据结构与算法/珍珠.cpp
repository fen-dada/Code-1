#include<iostream>
using namespace std;
const int N=110;
bool g[N][N];
int n,m;

int main()
{
    cin>>n>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        g[x][y]=true;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                g[i][j]=g[i][j] || (g[i][k] && g[k][j]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int iless=0,igreater=0;
        for(int j=1;j<=n;j++)
        {
            if(g[i][j]) iless++;
            if(g[j][i]) igreater++;
        }
        if(iless>=(n+1)/2 || igreater>=(n+1)/2) ans++;
    }
    cout<<ans;
}