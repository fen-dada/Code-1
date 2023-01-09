#include<iostream>
#include<cmath>
using namespace std;
const int N=110,INF=0x7fffffff;
double g[N][N],a[N][3];
double dis[N];
bool book[N];
int n,m,A,B;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[i][1]=x;
        a[i][2]=y;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) g[i][j]=0;
            else g[i][j]=INF;
        }
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        double t1,t2;
        t1=pow(a[u][1]-a[v][1],2);
        t2=pow(a[u][2]-a[v][2],2);
        g[u][v]=g[v][u]=sqrt(t1+t2);//一开始漏掉了对称初始化
    }
    cin>>A>>B;
    for(int i=1;i<=n;i++)
    {
        dis[i]=g[A][i];
    }
    book[A]=true;
    int u;
    for(int i=1;i<=n-1;i++)
    {
        int minnum=INF;
        for(int j=1;j<=n;j++)
        {
            if(minnum>dis[j] && !book[j]) minnum=dis[j],u=j;//每次找一个最小值出来作为中介点
        }
        book[u]=true;//一定要找到最小值再标记
        if(u==B) break;
        for(int j=1;j<=n;j++)
        {
            if(g[u][j]<INF && dis[u]+g[u][j]<dis[j])
            {
                dis[j]=dis[u]+g[u][j];
            }
        }
    }
    printf("%.2lf",dis[B]);
}