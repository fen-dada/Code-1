#include<iostream>
using namespace std;
int f[210];
int n,m;

int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        int w,v,s;
        cin>>w>>v>>s;
        if(s==0)
        {
            for(int j=w;j<=m;j++)
            {
                f[j]=max(f[j],f[j-w]+v);
            }
        }
        else
        {
            for(int j=m;j>=w;j--)
            {
                for(int k=0;k<=s;k++)
                {
                    if(j-w*k<0) break;
                    f[j]=max(f[j],f[j-w*k]+v*k);
                }
            }
        }
    }
    cout<<f[m];
}