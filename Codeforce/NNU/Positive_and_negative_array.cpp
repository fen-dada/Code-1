#include<iostream>
#include<cmath>
using namespace std;
const long long  N=2e5+100;
const long long  INF=0x3f3f3f3f;
long long a[N];
int main()
{
    int k;
    cin>>k;
    while(k--)
    {
        int idx;
        long long sum=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        long long m_ax=-INF,_max=-INF;
        for(int i=1;i<=n;i++)
        {
            if(a[i]<0)
            {
                m_ax=0;
                if(_max<a[i]) _max=a[i];
            }
            if(a[i]>0)
            {
                _max=0;
                if(m_ax<a[i]) m_ax=a[i];
            }
            if(a[i]*a[i+1]<0||i==n)
            {
                if(m_ax==0) 
                {
                    sum+=_max;
                    m_ax=-INF;
                    _max=-INF;
                }
                if(_max==0)
                {
                    sum+=m_ax;
                    _max=-INF;
                    m_ax=-INF;
                }
            }
        }
        cout<<sum<<endl;
    }
}