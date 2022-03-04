#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0;
        while(j<nums.size())
        {
            nums[i]=nums[j];
            i++;
            j++;
            while(j<nums.size()&&nums[j]==nums[j-1]) j++;
        }
        return i;
    }
};

int main()
{
    Solution slv;
    vector<int> nums = 
    {0,0,1,1,1,2,2,3,3,4};
    int ans = slv.removeDuplicates(nums);
    cout<<ans;
    return 0;
}