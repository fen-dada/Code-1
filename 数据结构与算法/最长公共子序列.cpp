#include<iostream>
#include<cstring>
using namespace std;
const int N=10010;
char a[N],b[N],t1[N],t2[N];
int f[N][N];
//这里strlen(a)就是0，咱也不知道咋回事
int main()
{
    cin>>t1>>t2;
    for(int i=0;i<strlen(t1);i++) a[i+1]=t1[i];
    for(int i=0;i<strlen(t2);i++) b[i+1]=t2[i];
    int len1=strlen(t1),len2=strlen(t2);
    for(int i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {
            //cout<<"?"<<endl;
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            if(a[i]==b[j])
            {
                f[i][j]=max(f[i][j],f[i-1][j-1]+1);
                cout<<f[i][j]<<endl;
            }
        }
    }
    cout<<f[len1][len2];
}


// ABCBDAB
// BDCABA