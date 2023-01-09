#include<iostream>
using namespace std;
const int N=2022,INF=0x3f3f3f3f;
double g[N][N];
double dis[N];
bool book[N];
int n,m,A,B;

int main()
{
    cin>>n>>m;
    while(m--)
    {
        int x,y;
        double z;
        cin>>x>>y>>z;
        g[x][y]=g[y][x]=(100-z)/100;
    }
    cin>>A>>B;
    for(int i=1;i<=n;i++)
    {
        dis[i]=g[A][i];
    }
    dis[A]=1;
    book[A]=true;
    int u;
    for(int i=1;i<=n-1;i++)
    {
        double maxnum=0;
        for(int j=1;j<=n;j++)
        {
            if(maxnum<dis[j] && !book[j]) maxnum=dis[j],u=j;
        }
        if(u==B) break;
        book[u]=true;
        for(int j=1;j<=n;j++)
        {
            if(!book[j] && dis[j]<dis[u]*g[u][j])
            {
                dis[j]=dis[u]*g[u][j];
            }
        }
    }
    printf("%.8lf",100/dis[B]);
}