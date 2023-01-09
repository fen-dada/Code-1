#include<iostream>
#include<cmath>
using namespace std;
double a[10000][2];
double rx,ry;
double k_1,k_2;
double x_2,x_3,y_3,y_2;

int main()
{
    for(int i=1;i<=3;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    x_2=(a[1][0]+a[2][0])/2;
    x_3=(a[1][0]+a[3][0])/2;
    double k1=abs((a[1][1]-a[2][1])/(a[1][0]-a[2][0]));
    double k2=abs((a[1][1]-a[3][1])/(a[1][0]-a[3][0]));
    k_1=(-1)/k1;
    k_2=(-1)/k2;
    rx=(a[2][0]*k1-a[3][0]*k2+a[3][1]-a[2][1])/(k1-k2);
    ry=k2*rx-a[3][0]*k2+a[3][1];
    if(a[1][0]-a[2][0]==0) k_1=0;
    if(a[1][0]-a[2][0]==0) k_2=0;
    if(a[1][1]==a[2][1]) rx=x_2;
    if(a[1][1]==a[3][1]) rx=x_3;
    double len;
    double t1=pow(rx-a[1][0],2);
    double t2=pow(ry-a[1][1],2);
    len=sqrt(t2+t1);
    cout<<k1<<" "<<k2<<" "<<len;
    printf("%.8lf %.8lf %.8lf",rx,ry,len);
}