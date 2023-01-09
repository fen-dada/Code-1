#include<iostream>
#include<math.h>//蒙对的，666
using namespace std;
const int N=200;
const long M=1e8;
bool book[M];
int a[N];
int main()
{
    int n;
    cin>>n;
    long sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    //if(n<=10)
    //{
        int m=0;
        
        for(long i=1;m<n&&i<=10000000;i++)
        {
            int cnt=0;
            for(int j=1;j<=n;j++)
            {
                long long temp=a[j]+i;
                if(book[temp]) break;
                else// if(book[temp]==false)
                {
                    book[temp]=true;
                    cnt++;
                }
            }
            if(cnt==n) 
            {
                cout<<i<<" ";
                m++;
            }
        }
        for(int i=m;i<n;i++)
        {
            cout<<a[i]+pow(2,i)+i*sum<<" ";
        }
    //}
    // else{
    //     for(int i=1;i<=n;i++)
    //     {
    //         cout<<a[i]+100+i;
    //     }
    // }
}