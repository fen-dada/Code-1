#include<iostream>
#include<algorithm>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
int a[N];
int max_num=0,min_num=0;
int max_x=-INF,min_x=INF;
int n,m;
void search()
{
    max_num=0;
    min_num=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==max_x) max_num++;
        if(a[i]==min_x) min_num++;
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    max_x=a[n],min_x=a[1];
    search();
    while(m--)
    {
        if(max_num>=min_num)
        {
            a[1]=max_x;
        }
        else {a[n]=min_x;}
        sort(a+1,a+n+1);
        max_x=a[n],min_x=a[1];
        search();
        cout<<max_num<<" "<<min_num<<endl;
    }
    cout<<a[n]-a[1];
}