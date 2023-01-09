#include<iostream>
#include<cmath>
using namespace std;
long long x;

// int find(int n)
// {
//     int i,j;
//     bool flag=true;
//     for(i=n+1;;i++)
//     {
//         for(j=2;j<i;j++)
//         {
//             if(i%j==0)
//             {
//                 break;
//             }
//         }
//         if(j==i) return i;
//     }
// }

// int dfs(int num,int n)
// {
//     bool is_prime=true;
//     int cnt;
//     if(n==1)
//     {
//         return find(num);
//     }
//     else if(n>1)
//     {
//         return dfs(find(num),n-1);
//     }
// }

int main()
{
    long long a,b;
    cin>>a>>b;
    for(long long i=a+1;;i++)
    {
        if(i%2==0 && i!=2) continue;
        long long j;
        bool flag=true;
        long long cnt=sqrt(i);
        for(j=2;j<=cnt;j++)
        {
            if(i%j==0)
            {
                flag=false;
                break;
            }
        }
        if(flag && b!=1) b--;
        else if(flag && b==1)
        {
            x=i;
            break;
        }
    }
    cout<<x-1;
}