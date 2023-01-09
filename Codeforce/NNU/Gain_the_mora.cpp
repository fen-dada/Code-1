#include<iostream>
using namespace std;
const int N=10010;
int a[N];
int main()
{
    int n;
    cin>>n;
    int cnt=n;
    int x,y;
    x=1,y=2;
    while(n--)
    {
        if(y<=cnt) cout<<"? "<<x<<" "<<y<<" "<<endl;
        if(y>cnt) cout<<"? "<<"2"<<" "<<"3"<<" "<<endl;
        y++;
        int num;
        cin>>num;
        a[cnt-n]=num;
    }
    cout<<"! "<<a[2]-a[cnt]<<" "<<a[cnt]-a[2]+a[1]<<" ";
    for(int i=2;i<=cnt-1;i++)
    {
        cout<<a[i]-a[i-1]<<" ";
    }
    cout<<endl;
}