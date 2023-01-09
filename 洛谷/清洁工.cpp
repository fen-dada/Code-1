#include<iostream>
using namespace std;
const int N=100,M=1010;
int a[N][N]={0},c[N][N];
char b[M];
int num;
int n,m,x,y;
void add()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]+=c[i][j];
        }
    }
}

void readd()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            c[i][j]++;
        }
    }
}

int main()
{
    cin>>n>>m>>x>>y;
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
    }
    int cnt=1;
    for(int i=1;i<=m;i++,cnt+=i)
    {
        readd();
        c[x][y]=0;
        add();
        if(b[i]=='N') y++;
        if(b[i]=='S') y--;
        if(b[i]=='W') x--;
        if(b[i]=='E') x++;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<a[j][n-i+1]<<" ";
        }
        cout<<endl;
    }
}