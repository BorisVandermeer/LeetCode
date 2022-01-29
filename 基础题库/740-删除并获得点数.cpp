#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int curnum = nums[0];
        int last_idx = 0;
        int cur_idx = 0;
        //选取第一个值
        for(cur_idx=1;cur_idx<nums.size()&&nums[cur_idx]==nums[0];cur_idx++);
        int val = cur_idx*curnum;
        if(cur_idx==nums.size()) return val;

        int prepre = 0;
        int pre = 0;
        int cur = val;
        last_idx = cur_idx;
        while(cur_idx<nums.size())
        {
            for(;cur_idx<nums.size()&&nums[cur_idx]==nums[last_idx];cur_idx++);
            int val = (cur_idx-last_idx)*nums[last_idx];
            int val2;
            if(nums[last_idx]-nums[last_idx-1]==1) val2 = max(pre,prepre)+val;
            else val2 = max(cur,pre)+val;

            prepre = pre;
            pre =cur;
            cur = val2;

            last_idx = cur_idx;
            if(cur_idx==nums.size()) return max(cur,pre);
        }
        return 1;
    }
};


int main()
{
    Solution slv;
    vector<int> vec = {2,3,4};
    return slv.deleteAndEarn(vec);
}
