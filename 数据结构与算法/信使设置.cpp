#include<iostream>
#include<cstring>
using namespace std;
int n,m;
const int N=110,INF=0x3f3f3f3f;
int g[N][N];

int main()
{
    memset(g,0x3f,sizeof(g));
    cin>>n>>m;
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=g[b][a]=min(g[a][b],c);//说是以后可能会输入更小的？
        g[a][a]=0;
        g[b][b]=0;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    int ans=-INF;
    for(int i=1;i<=n;i++)
    {
        if(g[1][i]==INF)
        {
            puts("-1");
            return 0;
        }
        ans=max(ans,g[1][i]);
    }
    cout<<ans;
}