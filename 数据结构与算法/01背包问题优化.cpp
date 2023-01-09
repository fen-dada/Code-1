#include<iostream>
using namespace std;
const int N=50;
int f[N];
int n,m;

int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        int w,v;
        cin>>w>>v;
        for(int j=m;j>=w;j--)//从后往前便利很重要，在优化有的01背包问题就要反过来
        {//因为是往前递推，所以前面的最大值可能就包含当前物品，到后面调用前面的最大值时后面可能也包含了物品，也就是一个选了多次
            f[j]=max(f[j],f[j-w]+v);//选了和没选
        }//直观点看就是从前往后找最大值时数字已经变过了，而反过来找最大值时仍是上一轮的最大值
    }
    cout<<f[m]<<endl;
}