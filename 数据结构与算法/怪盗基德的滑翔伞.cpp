#include<iostream>
#include<cstring>
using namespace std;
const int N=200;
int f[N];
int ans=0;
int a[N];
int n;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int ans=0;//没写这个直接寄
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            f[i]=1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(a[j]<a[i])
                {
                    f[i]=max(f[i],f[j]+1);
                }
            }
            ans=max(ans,f[i]);
        }
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
        {
            f[i]=1;
            for(int j=1;j<i;j++)
            {
                if(a[j]>a[i])
                {
                    f[i]=max(f[i],f[j]+1);
                }
            }
            ans=max(ans,f[i]);
        }
        cout<<ans<<endl;
    }
}