#include<iostream>
using namespace std;
int cnt=0,cnt1=0;
const int N=1e6+10;
int a[N],f[N];
bool flag=true;
int main()
{
    int n;
    cin>>n;
    int idx=1;
    for(int i=1;i<=n;i++)
    {
        string str;
        cin>>str;
        if(cnt<0||cnt1<0) flag=false;
        if(str=="?"||str==":") cnt1--;
        else cnt1++;
        if(i==1)
        {
            if(str=="?"|| str==":") flag=false;
        }
        if(str=="?")
        {
            cnt++;
        }
        else if(str==":")
        {
            cnt--;
        }
        //else a[idx++]=stoi(str);
    }
    //idx--;
    if(n<5) flag=false;
    if(cnt!=0) flag=false;
    if(idx%2==0) flag=false;
    if(cnt1!=1) flag=false;
    // for(int i=2;i<idx&&a[i];i++)
    // {
    //     if(!f[i]||!a[i]||!f[i+1]||!a[i+1]) flag=false;
    // }
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}