#include<iostream>
#include<vector>
using namespace std;
const int N=200200;
int a[N],b[N];
vector<int> ans;
int main()
{
    long long len1,len2;
    cin>>len1>>len2;
    for(long long i=len1;i>=1;i--)
    {
        cin>>a[i];
    }
    for(long long i=len2;i>=1;i--)
    {
        cin>>b[i];
    }
    long long len=max(len1,len2);
    int mar=0;
    int i;
    for(i=1;i<=len;i++)
    {
        int temp=a[i]+b[i]+mar;
        mar=temp/(i+1);
        temp%=(i+1);
        ans.push_back(temp);
    }
    while(mar!=0)
    {
        int temp=mar%(i+1);
        ans.push_back(temp);
        mar/=(i+1);
        i++;
    }
    while(ans.size()>1&&ans.back()==0)
    {
        ans.pop_back();
    }
    for(long long i=ans.size()-1;i>=0;i--)
    {
        cout<<ans[i]<<" ";
    }
}
