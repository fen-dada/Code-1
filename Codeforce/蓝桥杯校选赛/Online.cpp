#include<iostream>
#include<stdio.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int father[N],siz[N];
ll n,m,s;
int cnt=0;

int find(int x)
{
    if(x!=father[x])
    {
        x=father[x];
        return find(x);
    }
    return father[x];
}

void merge(int x,int y)
{
    x=find(x),y=find(y);
    if(x==y) return;
    if(siz[x]>siz[y]) swap(x,y);
    father[x]=y;
    siz[y]+=siz[x];//节点下面跟的点少的插到多的里面，用于优化
}
int main()
{
    freopen("3.txt","r",stdin);
    freopen("4.txt","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
    {
        father[i]=i;
        siz[i]=1;
    }
    for(ll i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        merge(x,y);
    }
    for(int i=1;i<=n;i++)
    {
        if(father[i]!=i) father[i]=find(father[i]);
    }
    int t=find(s);
    for(int i=1;i<=n;i++)
    {
        if(find(i)==t) cnt++;
        //cout<<father[i]<<endl;
    }
    cout<<cnt;
}