//nlogn
//利用二分查找降低复杂度
//使用贪心的思想，将辅助数组里的元素尽可能变小，但是不改变长度，所以仍是最大子序列
//遇到更小的时候将它覆盖掉第一个比他大的元素，依次往后
//因为是求最长的子序列，所以在不改变长度的情况下相当于选择了另一条子序列，而后者里面元素更小，更容易容纳更多的元素，实现最长的长度
#include<iostream>
using namespace std;
const int N=1010;
int a[N],b[N];
int n;
int len=1;

int idx(int x,int len)
{
    int l=0,r=len;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(b[mid]<x) l=mid;
        else r=mid-1;
    }
    return l;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    b[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        if(a[i]>b[len])
        {
            b[++len]=a[i];
            cout<<a[i]<<endl;
        }
        else
        {
            int p=idx(a[i],len);
            if(b[p] != a[i])//黑猫搜的是a[p]!=a[i]??啥意思？？
            {//难道不应该是原位置上不是a[i]的话就在后面一个插入a[i]吗
                b[p+1]=a[i];
            }
        }
    }
    cout<<len<<endl;
}

// 7
// 1 7 3 5 9 4 8