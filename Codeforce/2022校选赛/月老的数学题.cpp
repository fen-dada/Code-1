#include <iostream>
using namespace std;

void yuefen(long int &numerator, long int &denominator)
{
    //利用辗转相除法求最大公约数，b即为最大公约数
    long int a = numerator, b = denominator;
    long int temp = a % b;
    while(temp)
    {
        a = b;
        b = temp;
        temp = a % b;
    }
    
    numerator /= b;
    denominator /= b;
}

int main()
{
    //N组测试用例
    int T;
    cin>>T;
    while(T--)
    {
        //输入第1个数
        string input;
        cin>>input;
        unsigned long split = input.find("/");
        long int numerator = stoi(input.substr(0, split));
        long int denominator = stoi(input.substr(split + 1, input.size() - split - 1));
        cout<<split<<" "<<denominator<<endl;
        
        for(int i = 1; i < n; ++i)
        {
            //每处理六个数就进行约分
            if(i/6 == 0)
            {
                yuefen(numerator, denominator);
            }
            
            //取数
            cin>>input;
            split = input.find("/");
            long int numerator2 = stoi(input.substr(0, split));
            long int denominator2 = stoi(input.substr(split + 1, input.size() - split - 1));
            
            numerator = numerator * denominator2 + denominator * numerator2;
            denominator *= denominator2;
        }
        
        //约分
        yuefen(numerator, denominator);
        
        //输出
        //取整数部分
        long int integerPart = numerator / denominator;
        numerator %= denominator;
        //只有小数部分
        if(integerPart == 0)
        {
            //处理分母为负数的情况
            if(denominator < 0)
            {
                numerator = -numerator;
                denominator = abs(denominator);
            }
            
            //处理答案是0的情况
            if(numerator == 0)
            {
                cout<<numerator<<endl;
            }
            else
            {
                cout<<numerator<<"/"<<denominator<<endl;
            }
        }
        //有整数部分
        else
        {
            //没有小数部分
            if(numerator == 0)
            {
                cout<<integerPart<<endl;
            }
            //有小数部分
            else
            {
                cout<<integerPart<<" "<<numerator<<"/"<<denominator<<endl;
            }
        }
    }
    return 0;
}
