//外层循环从后向前，内层循环从前向后
//但方向不唯一，我还写了个反向的，证明了方向并不重要
//外层循环与辅助数组定义吻合，可在便利的同时完成从后向前的初始化，也就是必须先初始化f[j]才能递推出f[j-1]
#include<iostream>
using namespace std;
const int N=30;
int n;
int ans=0,st,idx;
int a[N],f[N];//f[i]表示从i到n最多有多少地雷（但并不代表一定取到n，只是表示一个方向）
bool g[N][N];//记录联通情况
int pre[N];//模拟链表

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=a[i];//每一个都至少是它本身
    }
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int x;
            cin>>x;
            if(x)
            {
                g[i][j]=true;
            }
        }
    }
    for(int i=n-1;i>=1;i--)
    {
        int maxv=0,idx=0;//是在i后面搜索到的最大的地雷数量
        for(int j=i+1;j<=n;j++)
        {
            if(g[i][j] && f[j]>maxv)//对于任意的一个位置j，只要和i联通且有最大值就满足条件，然后依次递推下去
            {
                maxv=f[j];
                idx=j;
            }
        }
        pre[i]=idx;
        f[i]+=maxv;//更新f[i]的值，加上在它身后的最大值，也就是在加上自己本身
        if(f[i]>ans)
        {
            ans=f[i];
            st=i;//因为外层循环从后向前，所以记录了开头
        }//否则就像反向那个里面还有一个入栈的过程
    }
    while(st)
    {
        cout<<st<<" ";
        st=pre[st];
    }
    cout<<endl<<ans;
}