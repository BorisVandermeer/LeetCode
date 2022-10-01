#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<utility>
#include<stack>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<string.h>


using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int ans = 0;
        if(dividend==-2147483648&&divisor==-1) return INT32_MAX;
        if(dividend==-2147483648&&divisor==1) return INT32_MIN;
        if(dividend==-2147483648&&divisor == dividend) return 1;
        if(divisor==-2147483648 ) return 0; 
        int flag = 1;
        if(divisor < 0)
        {
            divisor = -divisor;
            flag = -1;
        }
        if(dividend==-2147483648)
        {
            dividend+=divisor;
            dividend = -dividend;
            flag = -flag;
            ans = 1;
        }
        if(dividend<0)
        {
            dividend = -dividend;
            flag = -flag;
        }
        
        int & n =divisor;
        int m = 1;
        while(divisor<dividend&&divisor<=(INT32_MAX>>1))
        {
            divisor = divisor<<1;
            m = m<<1;
        }
        if(divisor>dividend)
        {
            divisor = divisor>>1;
            m = m>>1;
        }
        while(m)
        {
            if(dividend>=divisor)
            {
                dividend -= divisor;
                ans += m;
            }
            m = m>>1;divisor = divisor>>1;
        }
        if(flag == -1) return -ans;
        return ans;
    }
};

class Solution_Funny {
public:
    int divide(int dividend, int divisor) {
        if(dividend==-2147483648&&divisor==-1) return INT32_MAX;
        return dividend/divisor;
    }
};

int main()
{
    Solution slv;
    pair<int,int> input;
    input = 
    {123,10};

    auto ans = slv.divide(input.first,input.second);
    cout<<ans;
    return 0;
}

/*

给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2

*/