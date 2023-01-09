#include<iostream>
using namespace std;
int f[1010];
int n,m;

int main()
{
    f[0]=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int v;
        cin>>v;
        for(int j=m;j>=v;j--)
        {
            f[j]=f[j]+f[j-v];
        }
    }
    cout<<f[m]<<endl;
}