#include<iostream>
#include<cstring>
#include<cmath>
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
        char s[N],t[N];
        memset(s,0,sizeof str);
        memset(t,0,sizeof mode);
        bool is_find=false;
        //string s,t;
        int ans=1;
        cin>>s>>t;
        if(a_num(s)==0)
        {
            cout<<"1"<<endl;
            continue;
        }
        while(a_num(s_temp)!=0)
        {
            for(int i=0;i<s_temp.size();i++)
            {
                if(s_temp[i]=='a')
                {
                    s_temp.replace(i,1,t);
                    break;
                }
            }
            if(s_temp==s)
            {
                printf("1\n");
                is_find=true;
                break;
            }
            if(a_num(t)==1&&t.size()==1)
            {
                cout<<"1"<<endl;
                is_find=true;
                break;
            }
            if(a_num(s_temp)>=a_num(s)&&s_temp!=s)
            {
                printf("-1\n");
                is_find=true;
                break;
            }
            if(a_num(t)>=1)
            {
                cout<<"-1"<<endl;
                is_find=true;
                break;
            }
            if(a_num(t)>=1)
            {
                cout<<"-1"<<endl;
                break;
            }
            //ans++;
        }
        if(!is_find) 
        {
            long long ans=1<<a_num(s);
            printf("%lld\n",ans);
        }
    }
}