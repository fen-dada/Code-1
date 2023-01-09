#include<iostream>
using namespace std;
const int N=110;
int father[N];
int n,m;
int a[N];

void buildset()
{
    for(int i=1;i<=n;i++)
    {
        father[i]=i;
    }
}

int find(int x)
{
    if(father[x]!=x)
    {
        father[x]=find(father[x]);//优化后的压缩路径版本
    }
    return father[x];
}

void merge(int u,int v)
{
    father[v]=u;
}

int main()
{
    cin>>n>>m;
    buildset();
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        int t1=find(x);
        int t2=find(y);
        if(t1!=t2) merge(x,y);
    }
    for(int i=1;i<=n;i++)
    {
        a[find(i)]++;
    }
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++)
    {
        if(cnt2<a[i]) cnt2=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(father[i]==i) cnt1++;
    }
    cout<<cnt1<<" "<<cnt2<<endl;
}