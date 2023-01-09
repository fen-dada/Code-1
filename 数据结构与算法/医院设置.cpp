#include<iostream>
#include<cstring>
using namespace std;
const int N=110,INF=0x3f3f3f3f;
int g[N][N];
int n;
int res=INF;
int cnt[N];

int main()
{
    memset(g,0x3f,sizeof(g));
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int m,x,y;
        cin>>m>>x>>y;
        g[i][i]=0;
        cnt[i]=m;
        if(x) g[i][x]=g[x][i]=1;
        if(y) g[i][y]=g[y][i]=1;
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
    for(int i=1;i<=n;i++)//枚举医院的位置
    {
        int sum=0;
        for(int j=1;j<=n;j++)//枚举其他地点到医院
        {
            sum+=g[i][j]*cnt[j];
        }
        res=min(res,sum);
    }
    cout<<res;
}