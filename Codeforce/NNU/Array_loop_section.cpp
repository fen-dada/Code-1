#include<iostream>
using namespace std;
const int N=200;
int a[N];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int cnt=n/k;
    int sum=0;
    int head=1,tail=(cnt-1)*k+1;
    for(;tail<=n;head++,tail++)
    {
        int x=0,y=0;//x为2改1，y为1改2
        for(int i=head;i<=tail;i+=k)
        {
            if(a[i]==2) x++;
            if(a[i]==1) y++;
        }
        int m=min(x,y);
        sum+=m;
    }
    cout<<sum<<endl;
}