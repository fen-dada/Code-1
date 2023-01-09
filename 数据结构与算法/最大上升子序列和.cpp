#include<iostream>
using namespace std;
const int N=1010;
int n;
int a[N],f[N];//记录以当前元素结尾的最大上升子序列的和的值
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=a[i];//开始每个都是自己
    }
    int ans=a[1];
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(a[j]<a[i])
            {
                f[i]=max(f[i],f[j]+a[i]);
            }
        }
        ans=max(ans,f[i]);
    }
    cout<<ans;
}