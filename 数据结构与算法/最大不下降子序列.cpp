//n^2
#include<iostream>
using namespace std;
int a[210][3];
int n;
int ans=1;
int ie=0;
int stk[210],top=0;
//第一行存值
//第二行存以当前元素结尾的最大条件子序列的长度
//第三行存子序列中前一个元素的下标

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][0];
        a[i][1]=1;//默认只有自己的序列长度为1
    }
    for(int i=2;i<=n;i++)
    {
        int maxlen=0,idx=0;
        for(int j=1;j<i;j++)//不能搜自己，如果搜自己那第三层的下标就会变成自己
        {
            if(a[j][0]<=a[i][0] && a[j][1]>maxlen)//只要选出一个比我小且它存的子序列最大就行了（因为有存序列的长度，因此不需要用贪心的思想把它都变成最小的）
            {
                maxlen=a[j][1];
                idx=j;
            }
        }
        if(maxlen)//如果情况改变
        {
            a[i][1]=maxlen+1;
            a[i][2]=idx;
            //ie=idx;
            if(a[i][1]>ans)
            {
                ans=a[i][1];
                ie=idx;
            }
        }
    }
    cout<<"max="<<ans<<endl;
    if(!ie)//只有自己
    {
        cout<<a[1][0]<<endl;
        return 0;
    }
    while(ie)
    {
        stk[++top]=a[ie][0];
        ie=a[ie][2];
        cout<<a[ie][0]<<endl;
    }
    while(top)
    {
        cout<<stk[top--]<<" ";
    }
}

// 14
// 13 7 9 16 38 24 37 18 44 19 21 22 63 15