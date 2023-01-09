#include<iostream>
#include<cstring>
using namespace std;
const int N=1010;
int n,m,k;
int f[N][N];

int main(){
    cin>>m>>n>>k;
    memset(f,0x3f,sizeof(f));
    f[0][0]=0;
    for(int i=1;i<=k;i++)
    {
        int v1,v2,v;
        cin>>v1>>v2>>v;
        for(int j=m;j>=0;j--)
        {
            f[m][0]=0;//或者把下面的改成p>=0.理解起来就是边界条件。（或者可以认为有些罐子只有氧气或只有氮气）
            for(int p=n;p>=1;p--)
            {
                f[j][p]=min(f[j][p],f[max(0,j-v1)][max(0,p-v2)]+v);
            }
        }
    }
    cout<<f[m][n];
}