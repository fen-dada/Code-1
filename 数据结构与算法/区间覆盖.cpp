#include<iostream>
#include<algorithm>
using namespace std;
const int N=10010;
struct range{
    int head,tail;
    bool operator< (const range &x) const{
        if(head==x.head) return tail>x.tail;
        return head<x.head;
    }
}r[N];

int main()
{
    int left,right;
    cin>>left>>right;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i].head>>r[i].tail;
    }
    sort(r+1,r+n+1);
    int ans=0;
    int pre=left;
    for(int i=1;i<=n;i++)
    {
        if(r[i].head>=pre)
        {
            ans++;
            pre=r[i].tail;
        }
    }
    cout<<ans<<endl;
}