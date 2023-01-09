#include<iostream>
using namespace std;
const int N=1010;
int f[N][N];
int n,m,k;

int main()
{
    cin>>n>>m>>k;
    while(k--)
    {
        int v1,v2;
        cin>>v1>>v2;
        for(int i=n;i>=v1;i--)
        {
            for(int j=m-1;j>=v2;j--)//也就是至少要留下一格能量，只拿出m-1来抓
            {
                f[i][j]=max(f[i][j],f[i-v1][j-v2]+1);
            }
        }
    }
    cout<<f[n][m-1]<<" ";
    int t=m-1;
    while(t>0 && f[n][t-1]==f[n][m-1]) t--;//这里利用t和m对等，因此形式上也写作对等的
    cout<<m-t;
}