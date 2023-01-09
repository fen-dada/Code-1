#include<iostream>
#include<math.h>
using namespace std;

int bit(int x)
{
    int ans=0;
    while(x!=0)
    {
        ans++;
        x/=10;
    }
    return ans;
}
//nmsl
int main()
{
    int num,a,b;
    cin>>num>>a>>b;
    if(a<b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    int n=bit(num);
    long int cnt=pow(10,n+1);
    int e=pow(10,n-1);
    if(num<b*e) num=b*e;
    //if(num>b*e&&num<a*e) num=a*e;
    for(long int i=num;i<=cnt;i++)
    {
        int x=0,y=0,z=0;
        int h=i;
        while(h!=0)
        {
            if(h%10==a) x++;
            if(h%10==b) y++;
            if(h%10!=a&&h%10!=b) {z++;break;}
            h/=10;
        }
        if(z==0&&x==y) {cout<<i<<endl;exit(0);}
    }
    return 0;
}