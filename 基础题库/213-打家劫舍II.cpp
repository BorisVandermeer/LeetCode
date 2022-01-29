#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        // nums[0] 不偷,其他就都可以偷了
        int prepre = 0;
        int pre = 0;
        int cur = nums[1];
        for(int i = 2;i<nums.size();i++)
        {
            int val = max(pre,prepre)+nums[i];
            prepre = pre;
            pre = cur;
            cur = val;
        }
        int ans = max(cur,pre);
        prepre = 0;
        pre = nums[0];
        cur = 0;
        for(int i = 2;i<nums.size()-1;i++)
        {
            int val = max(pre,prepre)+nums[i];
            prepre = pre;
            pre = cur;
            cur = val;            
        }
        ans = max(ans,max(cur,pre));
        return ans;
    }
};

int main()
{
    Solution slv;
    vector<int> vec = {2,1};
    return slv.rob(vec);
}