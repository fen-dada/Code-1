#include<iostream>
#include<cstring>
using namespace std;
const int N=110,INF=0x3f3f3f3f;
int g[N][N];
int n,S;

int main()
{
    cin>>n>>S;
    memset(g,INF,sizeof(g));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            string str;
            cin>>str;
            if(str!="-") g[i][j]=stoi(str);
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i!=S) printf("(%d -> %d) = %d\n",S,i,g[S][i]);
    }
}