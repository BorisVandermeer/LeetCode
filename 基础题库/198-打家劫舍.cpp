#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& num) {
        vector<int> nums(num);
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int m = nums.back();
        nums.pop_back();
        int n = rob(nums);
        nums.pop_back();
        m+=rob(nums);
        if(m>n) return m;
        return n;
    }
};

class Solution2 {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;
        for(int i=0;i<nums.size();i++)
        {
            a = b;
            b = c;
            c = d;
            if(a>b) d = nums[i] + a;
            else d = nums[i] + b;
        }
        if(d>c) return d;
        return c;
    }
};

int main()
{   
    Solution2 slv;
    vector<int> nums = {0};
    return slv.rob(nums);
}