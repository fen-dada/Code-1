#include<iostream>
using namespace std;
long calc(int x)
{
    long int ans=0;
    int n=x/60;//n为小时
    int m_1,m_2;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=60;j++)
        {
            if(j==0)
            {
                m_1=0;
                m_2=0;
            }
            if(j!=0){
                m_2=j%10;
                m_1=(j/10)%10;
            }
            if(i<10)
            {
                if(i-m_1==m_1-m_2) ans++;
            }
            if(i>=10)
            {
                int n_1=(i/10)%10;
                int n_2=i%10;
                if((n_1-n_2==n_2-m_1)&&(n_2-m_1==m_1-m_2)) ans++;
            }
        }
    }
    int mar=x-n*60;
    for(int i=0;i<=mar;i++)
    {
        if(i==0)
        {
            m_2=0;
            m_1=0;
        }
        if(i!=0)
        {
            m_2=i%10;
            m_1=(i/10)%10;
        }
        
        if(n+1<10)
        {
            if(-m_1==m_1-m_2) ans++;
        }
        if(n+1>=10)
        {
            int n_1=((n+1)/10)%10;
            int n_2=(n+1)%10;
            if((n_1-n_2==n_2-m_1)&&(n_2-m_1==m_1-m_2)) ans++;
        }
    }
    return ans;
}


int main()
{
    int num;
    int var;
    cin>>num;
    int t=num/1440;
    int m=num%1440;
    if(m!=0) var=t+1;
    if(m==0) var=t;
    long ans=(long)t*40-var+calc(m);
    printf("%ld",ans);
}