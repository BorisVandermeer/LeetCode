#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = 0;
        int max_idx = 0;
        int submax = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>max)
            {
                submax = max;
                max_idx = i;
                max = nums[i];
            }
            else if(nums[i]>submax) submax = nums[i];
            cout<<i<<"  "<<max_idx<<endl;
        }
        if(max>=2*submax) return max_idx;
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3,6,1,0};
    return s.dominantIndex(nums);
}