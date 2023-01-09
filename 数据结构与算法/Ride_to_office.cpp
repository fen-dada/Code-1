#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int INF=0x3f3f3f3f;
int main()
{
    int n;
    while(cin>>n,n)
    {
        int v,t;
        double total,ans=INF;
        for(int i=1;i<=n;i++)
        {
            cin>>v>>t;
            if(t<0) continue;
            total=4.5/v*3600;
            total=ceil(total)+t;
            ans=min(ans,total);
        }
        cout<<(int)ans<<endl;
    }
}
// 4
// 20 0
// 25 -155
// 27 190
// 30 240
//===========780
//提前出发的不用管
//我们的时间和最后的那个人相同，因为是同时到终点的，再加上我比他早走的那点时间行