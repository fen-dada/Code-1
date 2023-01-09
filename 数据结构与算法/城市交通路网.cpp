#include<iostream>
#include<cstring>
using namespace std;
const int N=5010,INF=0x3f3f3f;
int g[N][N];
int n;
int f[N];
int pre[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>g[i][j];
        }
    }
    memset(f,0x3f,sizeof(f));
    f[n]=0;
    for(int i=n-1;i>=1;i--)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(g[i][j]>0&&f[j]<INF&&f[i]>g[i][j]+f[j])
            {
                //f[i]=min(f[i],f[j]+g[i][j]);
                f[i]=g[i][j]+f[j];
                pre[i]=j;//严格大于了，要更新f[i]了再存前驱，不然就一直存的是最后一个进来的
            }//两者等价，但是相当于判断了只有大于的时候才是适合的前驱，然后通过不断覆盖找到一个最小的
        }
    }
    cout<<"minlong="<<f[1]<<endl;
    int i=1;
    while(i)
    {
        cout<<i<<" ";
        i=pre[i];
    }
}