#include<iostream>
 
using namespace std;

// 这个解法的问题是可能会溢出 
class Solution_Failed_1 {
public:
    int mySqrt(int x) {
        int ans = 0;
        int last_bit = 0;
        for(;x/(ans+(1<<last_bit))>=ans+(1<<last_bit);last_bit++);
        while(last_bit!=0)
        {
            ans += (1<<(last_bit-1));
            for(last_bit = 0;(ans+(1<<last_bit))*(ans+(1<<last_bit))<=x;last_bit++);
            //cout<<"last_bit:"<<last_bit<<"; ans:"<<ans<<endl;
        }
        return ans;
    }
};

class Solution {
public:
    int mySqrt(int x) {
        if(x<=1) return x;
        int ans = 0;
        int last_bit = 0;
        for(;x/(ans+(1<<last_bit))>=ans+(1<<last_bit);last_bit++);
        while(last_bit!=0)
        {
            ans += (1<<(last_bit-1));
            for(last_bit=0;x/(ans+(1<<last_bit))>=(ans+(1<<last_bit));last_bit++);
            cout<<"last_bit:"<<last_bit<<"; ans:"<<ans<<endl;
        }
        return ans;
    }
};

int main()
{
    Solution slv;
    return slv.mySqrt(2147395599);
}