#include<iostream>
using namespace std;
#include<algorithm>
const int N=5020;
typedef pair<int,int> PII;
PII p[N];
int n;
int f[N];
int ans=0;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].first>>p[i].second;
        f[i]=1;
    }
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(p[j].second<p[i].second)
            {
                f[i]=max(f[i],f[j]+1);
            }
        }
        ans=max(ans,f[i]);
    }
    cout<<ans<<endl;
}