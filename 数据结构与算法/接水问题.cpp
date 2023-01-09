#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int n,k;
    priority_queue<int,vector<int>,greater<int> > q;
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        q.push(0);//控制q的大小，保证一下只有k个位置，模拟k个水龙头
    }
    while(n--)
    {
        int x;
        cin>>x;//接水顺序已经确定
        int t=q.top();
        q.pop();
        q.push(x+t);//先做好的先出，顺序接上后面的
    }
    while(q.size()>1)
    {
        q.pop();
    }
    cout<<q.top()<<endl;
}