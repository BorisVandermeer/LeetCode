#include<iostream>
#include<vector>

using namespace std;

//递归
class Solution1 {
public:
    int addDigits(int num) {
        if(num<10) return num;
        int ans = 0;
        while(num)
        {
            ans+=num%10;
            num=num/10;
        }
        return addDigits(ans);
    }
};
// 迭代
class Solution {
public:
    int addDigits(int num) {
        while(num>=10)
        {
            int numbackup = num;
            num = 0;
            while(numbackup)
            {
                num+=numbackup%10;
                numbackup=numbackup/10;
            }
        }
        return num;
    }
};

int main()
{
    Solution slv;
    int num = 38;
    int ans = slv.addDigits(num);
    cout<<ans;
    return 0;
}