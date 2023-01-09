#include<iostream>
#include<algorithm>
using namespace std;
#include<queue>
const int N=30030;
int a[N];
int main()
{
    priority_queue<int, vector<int>, greater<int> > q;
    int w;
    cin>>w;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        //q.push(a[i]);
    }
    sort(a+1,a+n+1);
    int ans=0;
    int head=0,tail=n;
    while(head<tail)
    {
        int sum=0;
        sum+=a[head++]+a[tail--];
        if(sum<=w)
        {
            ans++;
            sum=0;
        }
        else
        {
            ans++;
            head--;
        }
    }
    if(head==tail) ans++;
    cout<<ans<<endl;
}