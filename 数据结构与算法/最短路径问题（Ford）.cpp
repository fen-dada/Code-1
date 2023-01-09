#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
const int N=10001;
int u[N],v[N],a[N][3];
double w[N],dis[N];
int n,m,s,t;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][1]>>a[i][2];
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i];
        double t1=pow(a[v[i]][1]-a[u[i]][1],2.0);
        double t2=pow(a[v[i]][2]-a[u[i]][2],2.0);
        w[i]=sqrt(t1+t2);
    }
    cin>>s>>t;
    memset(dis,0x7f,sizeof dis);
    dis[s]=0;
    for(int i=1;i<=n-1;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(dis[v[j]]>dis[u[j]]+w[j]) dis[v[j]]=dis[u[j]]+w[j];
            if(dis[u[j]]>dis[v[j]]+w[j]) dis[u[j]]=dis[v[j]]+w[j];
        }
    }
    bool flag=false;
    for(int i=1;i<=m;i++)//检测有无负边权回路
    {
        if(dis[u[i]]>dis[v[i]]+w[j]) flag=true;//此时已经是最小值了，如果还能小，只能是负边权回路
    }
    if(flag)
    {
        cout<<"有负边权回路"<<endl;
        return 0;
    }
    printf("%.2lf",dis[t]);
    return 0;

    //还有一个检测是否已经找到最短路径提前结束的就不过多赘述了
}