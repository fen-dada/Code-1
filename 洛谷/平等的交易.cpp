#include<iostream>
#include<algorithm>
using namespace std;
const int N=100100;
long a[N];
long sum[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    long w;
    cin>>w;
    sort(a+1,a+n+1);
    long index;
    for(int i=1;i<=n;i++)
    {
        if(i==1) sum[i]=a[i];
        else{
            sum[i]=sum[i-1]+a[i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]>0)
        {
            index=i;
            break;
        }
    }
    long ans=0;
    for(int i=n;i>=1;i--)
    {
        if(a[i]<=w)
        {
            w=a[i];
            break;
        }
    }
    ans+=1;
    for(int i=index;i<=n;i++)
    {
        if(sum[i]>w)
        {
            ans+=i-index-1;
            break;
        }
    }
    if(index!=1)
    {
        ans=ans-2+index;
    }
    cout<<ans;
}