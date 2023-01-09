#include<iostream>
using namespace std;
const int N=10010;
int a[N];
int main()
{
    int n;
    cin>>n;
    int cnt=n;
    while(n--)
    {
        int x,y;
        x=1,y=2;
        if(y<=n) cout<<"? "<<x<<" "<<y<<" "<<endl;
        if(y>n) cout<<"? "<<"2"<<" "<<"3"<<" "<<endl;
        int num;
        cin>>num;
        a[cnt-n]=num;
    }
    cout<<"! "<<a[2]-a[cnt]<<" "<<a[cnt]-a[2]+a[1]<<" "<<endl;
    for(int i=3;i<=cnt-1;i++)
    {
        cout<<a[i]-a[i-1]<<" "<<endl;
    }
}