#include<iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        int line = 0x7fffffff/10;
        int flag = 0; 
        if(x==-2147483648) return 0;
        if(x<0)
        {
            flag = 1;
            x = -x;
        }
        while(x)
        {
            if(rev>line) return 0;
            rev = rev*10;
            int t = x%10;
            if(t>0x7fffffff-rev) return 0;
            rev=rev+t;
            x = x/10;
        }
        if(flag==1) rev = -rev;
        return rev;
    }
};

int main()
{   
    Solution slv;
    auto ans = slv.reverse(-2147483648);
    cout<<ans<<endl; //String || int 
    return 1;
}