//主要思路是以a[]数组为主要讨论，（隐含了条件：f[i][j]代表的含义是以b[j]为结尾的子序列）每一个情况分为选a[i]和不选
//如果不选就跳回道a[i-1]（因为这里对每一个a[i]进行讨论，所以a数组的每一个元素都要便利一遍，然后分为选与不选
//这里跳回i-1 时，相当于跳回去讨论i-1的情况，而这种情况本身又包含了选i-1和不选i-1，因此不用在上一种情况里讨论
//-------所以主旋律是a数组，一定要以a数组为中心讨论
//如果选择了，那说明了现在a[i]是最大的元素，同时又是以b[j]结尾的子序列，所以两者是相等的
//因为已经以a为主选择了元素，于是跳回对f[i-1][j-n]的讨论，而它的意思是已经确定b[j]在序列中，但不确定之前的
//所以我对1-（j-1）的b数组便利，跳回了对单个数组最长上升子序列的分析
//最后将两种情况取最大值
//具体表现为：先初始化为第一种情况，在和第二种情况取max
#include<iostream>
using namespace std;
const int N=10010;
int n,m;
int a[N],b[N];
int f[N][N];
int pre[N];
int stk[N],top=0;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;i++) cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            f[i][j]=f[i-1][j];
            if(a[i]==b[j])
            {
                int maxlen=1;
                for(int k=1;k<j;k++)
                {
                    if(b[k]<b[j]&&f[i][k]+1>maxlen)
                    {
                        maxlen=f[i][k]+1;
                        pre[j]=k;
                    }
                }
                f[i][j]=max(f[i][j],maxlen);
            }
        }
    }
    int ans=0,iend=0;
    for(int i=1;i<=m;i++)
    {
        if(f[n][i]>ans) ans=f[n][i];
        iend=i;
    }
    cout<<ans<<endl;
    while(iend)
    {
        stk[++top]=b[iend];
        iend=pre[iend];
    }
    while(top)
    {
        cout<<stk[top--]<<" ";
    }
}


// 5
// 1 4 2 5 -12
// 4
// -12 1 2 4