#include<iostream>
using namespace std;
typedef long long ll;
const int N=1e6+10;
const ll M=1e9+7;
int a[N];

ll fact(ll x)
{
    if(x==0) return 0;
    ll sum=1;
    for(ll i=1;i<=x;i++)
    {
        sum*=i;
        sum%=M;
    }
    return sum;
}

int main()
{
    int n;
    ll sum=0;
    ll cnt=1;
    ll ans;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]) cnt*=fact(a[i]);
        cnt%=M;
    }
    sum=fact(sum);
    sum%=(ll)M;
    ans=sum/cnt;
    ans%=(ll)M;
    cout<<ans;
}