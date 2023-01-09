#include<iostream>//当有遍历时，最好将作为大多数的非极大点作为程序标记点，最后输出！的点
#include<algorithm>
using namespace std;
const int N=110;
bool book[N];
struct Node{
    int x,y;
    bool operator< (const Node &temp) const{
        if(x==temp.x) return y<temp.y;
        return x<temp.x;
    }
}node[N];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>node[i].x>>node[i].y;
    }
    sort(node+1,node+n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            // if(node[j].y>=node[i].y)
            // {
            //     //book[j]=true;
            //     book[i]=true;//标记不是极大点的点
            //     break;
            // }
        }
        //book[i]=true;
        // if((node[i+1].x>node[i].x) && (node[i+1].y<node[i].y))
        // {
        //     book[i]=true;
        //     book[i-1]=false;
        // }
    }
    bool is_first=true;
    for(int i=1;i<=n;i++)
    {
        if(!book[i])
        {
            if(is_first)
            {
                printf("(%d,%d)",node[i].x,node[i].y);
                is_first=false;
            }
            else
            {
                printf(",(%d,%d)",node[i].x,node[i].y);
            }
        }
    }
}