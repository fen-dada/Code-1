#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int a[N],b[N],b2[N];//a为原始属于，后面两个分别为存放子序列的辅助数组
int n=1,len=1,len2=1;
int main()
{
    while(scanf("%d",&a[n])==1) n++;//在此编译器中必须输入一个非整形数据才能结束循环
    n--;
    b[1]=b2[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        if(a[i]<=b[len]) b[++len]=a[i];
        else b[upper_bound(b+1,b+len+1,a[i],greater<int>() )-b]=a[i];//查找第一个大于等于它的指针
        
        if(a[i]>b2[len2]) b2[++len2]=a[i];
        else b2[lower_bound(b2+1,b2+len2+1,a[i])-b2]=a[i];//查找第一个小于它的指针
    }//最大上升子序列有多长就说明有几个下降子序列，自己体会一下
    cout<<len<<endl<<len2<<endl;
    return 0;
}