#include<iostream>
using namespace std;
int m,n;
const int N=100;
int f[35][205];

int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        int w,v;
        cin>>w>>v;
        for(int j=1;j<=m;j++)//不要从w开始便利不然会少很多状态
        {//直观的理解就是当你不选当前这个物品时，你也不一定去选上一个
            if(j>=w) f[i][j]=max(f[i-1][j],f[i-1][j-w]+v);
            else f[i][j]=f[i-1][j];
        }//因此当递推到i-1时，要有机会落到i-2
    }//说白了就是没有便利到的f[i][j]也要有值，不然就会加到空气
    cout<<f[n][m]<<endl;
}