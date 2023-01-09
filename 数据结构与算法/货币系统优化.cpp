#include<iostream>
using namespace std;
const int N=5010;
int f[N];
int n,m;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int v;
        cin>>v;
        f[v]+=1;
        for(int j=v;j<=m;j++)
        {
            f[j]=f[j]+f[j-v];
        }
    }
    cout<<f[m]<<endl;
}

