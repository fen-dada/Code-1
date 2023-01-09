#include<iostream>
using namespace std;
const int N=200;
int a[N][N],f[N][N];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int r,c;
        cin>>r>>c;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                cin>>a[i][j];
            }
        }
        //f[1][1]=a[1][1];
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                f[i][j]=max(f[i][j-1],f[i-1][j])+a[i][j];
            }
        }
        cout<<f[r][c]<<endl;
    }
}