#include<iostream>
using namespace std;
const int N=220;
bool g[N][N];
int n;
int father[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        while(cin>>x && x!=0)
        {
            g[i][x]=true;
        }
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
    for(int i=1;i<=n;i++)
    {
        father[i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(g[i][j]) father[j]=father[i];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(father[i]==i) ans++;
    }
    cout<<ans;
}