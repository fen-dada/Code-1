#include<iostream>
#include<cstring>
using namespace std;
const int N=10010;
int a_num(char* x)
{
    int num=0;
    for(int i=0;i<strlen(x);i++)
        {
            if(x[i]=='a')
            {
                num++;
            }
        }
    return num;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        //string s,t;
        char s[N],t[N];
        memset(s,0,sizeof s);
        memset(t,0,sizeof t);
        cin>>s>>t;
        long long m=a_num(s);
        //char s_temp[N];
        if(m==0)
        {
            cout<<'1'<<endl;
        }
        else if(a_num(t)>=1)
        {
            printf("-1\n");
        }
        else if(strlen(t)==1&&a_num(t)==1)
        {
            cout<<'1'<<endl;
        }
        else
        {
            long long ans=1<<m;
            printf("%lld",ans);
        }
    }
    return 0;
}


// #include<iostream>
// #include<cstring>
// using namespace std;
// const int N=10010,INF=0x3f3f3f3f;

// char str[N],mode[N];
// int cnt1,cnt2,T;
// long long t=1;

// int main()
// {
//     cin>>T;
//     while(T--)
//     {
//         memset(str,0,sizeof str);
//         memset(mode,0,sizeof mode);
//         cnt1=0;
//         cnt2=0;
//         cin>>str>>mode;
//         for(int i=0;str[i];i++)
//         {
//             if(str[i]=='a') cnt1++;
//         }
//         for(int i=0;mode[i];i++)
//         {
//             if(mode[i]=='a') cnt2++;
//         }
//         if(cnt1==0) cout<<'1'<<endl;
//         else if(cnt2==1&&strlen(mode)==1) cout<<'1'<<endl;
//         else if(cnt2>=1) printf("-1\n");
//         else printf("%lld\n",t<<cnt1);
//     }
//     return 0;
// }