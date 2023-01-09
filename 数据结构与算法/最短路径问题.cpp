#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
const int N=110;
double g[N][N];
int n,m;
int a[N][2];

double calc(int p1,int p2)
{
    double t1=pow(a[p1][0]-a[p2][0],2);
    double t2=pow(a[p1][1]-a[p2][1],2);
    return sqrt(t1+t2);
}

int main()
{
    cin>>n;
    memset(g,0x7f,sizeof g);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    cin>>m;
    while(m--)
    {
        int p1,p2;
        cin>>p1>>p2;
        g[p1][p2]=g[p2][p1]=calc(p1,p2);//无向图，注意初始化的对称性
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
    int s,t;
    cin>>s>>t;
    printf("%.2lf",g[s][t]);
}