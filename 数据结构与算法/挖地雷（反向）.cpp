#include<iostream>
using namespace std;
const int N=30;
int n;
int ans=0,ed,idx;
int a[N],f[N];//f[i]表示从1到i最多有多少地雷
bool g[N][N];
int pre[N];
int stk[N],top=0;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=a[i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int x;
            cin>>x;
            if(x)
            {
                g[i][j]=true;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        int maxv=0,idx=0;
        for(int j=i-1;j>=1;j--)
        {
            if(g[j][i] && f[j]>maxv)
            {
                maxv=f[j];
                idx=j;
            }
        }
        pre[i]=idx;
        f[i]+=maxv;
        if(f[i]>ans)
        {
            ans=f[i];
            ed=i;
        }
    }
    while(ed)
    {
        stk[++top]=ed;
        ed=pre[ed];
    }
    while(top)
    {
        cout<<stk[top--]<<" ";
    }
    cout<<endl<<ans;
}