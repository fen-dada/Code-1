//反正一个物品可以选很多次，所以按顺序来每一个容量都取一个最大值，然后向前递推
#include<iostream>
using namespace std;
int n,m;
int f[500];
int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        int w,v;
        cin>>w>>v;
        for(int j=w;j<=m;j++)//保证不越界
        {
            f[j]=max(f[j],f[j-w]+v);//每次都往大的挑，懂得都懂
        }
    }
    cout<<"max="<<f[m]<<endl;
}