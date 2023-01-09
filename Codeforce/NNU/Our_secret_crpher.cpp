#include<iostream>
using namespace std;
int calc(int x)
{
    return (x*(x+1))/2;
}
int main()
{
    int size;
    int cnt=1;
    string a;
    cin>>size>>a;
    cout<<a[0];
    int i=2,j=1;
    while(j<size)
    {
        cout<<a[j];
        i++;
        j+=i;
    }
}