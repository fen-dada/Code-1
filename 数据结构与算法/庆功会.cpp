#include<iostream>
using namespace std;
int f[6600];
int n,m;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int v,w,s;
        cin>>v>>w>>s;
        for(int j=m;j>=w;j--)
        {
            for(int k=0;k<=s;k++)
            {
                if(j-k*v<0) break;
                f[j]=max(f[j],f[j-k*v]+k*w);
            }
        }
    }
    cout<<f[m];
}