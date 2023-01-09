#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e4+100,INF=0x3f3f3f3f;
int n,m;
int a[N];
struct Student
{
    string name;
    int id;
    double cnt,sum,bit;
    bool operator<(const Student&b)const{
        if(this->bit==b.bit) return this->id<b.id;
        return this->bit>b.bit;
    }
}s[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int t;
        string str;
        cin>>t>>str;
        s[i].name=str;
        s[i].id=t;
        a[t]=i;
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int t;
        cin>>t;
        int idx=a[t];
        string str;
        cin>>str;
        double temp;
        if(str=="A+") temp=4.5;
        if(str=="A") temp=4.0;
        if(str=="B+") temp=3.5;
        if(str=="B") temp=3.0;
        if(str=="C+") temp=2.5;
        if(str=="C") temp=2.0;
        if(str=="D+") temp=1.5;
        if(str=="D") temp=1.0;
        if(str=="F-"||str=="F") temp=0;
        double score;
        int b;
        cin>>score>>b;
        s[idx].cnt+=temp*score*(1.0+0.2*(b==1));
        s[idx].sum+=score*(1.0+0.2*(b==1));
    }
    for(int i=1;i<=n;i++)
    {
        s[i].bit=s[i].cnt/s[i].sum;
    }
    sort(s+1,s+n+1);
    cout<<"The king of involution is "<<s[1].name<<".";
}