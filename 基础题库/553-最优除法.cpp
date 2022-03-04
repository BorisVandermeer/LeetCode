#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ans;
        ans+=to_string(nums[0]);
        if(nums.size()==1) return ans;
        if(nums.size()==2) return ans+to_string(nums[1]);
        ans+="/(";
        ans+=to_string(nums[1]);
        for(int i=2;i<nums.size();i++)
        {
            ans+='/';
            ans+=to_string(nums[i]);
        }
        return ans+')';
    }
};

// 不是，这也能动态规划？？
class Solution_Key{
public:
    string optimalDivision(vector<int>& nums) {
        string ans;
        ans+=to_string(nums[0]);
        if(nums.size()==1) return ans;
        if(nums.size()==1) return ans+to_string(nums[1]);
        ans+="/(";
        ans+=to_string(nums[1]);
        for(int i=2;i<nums.size();i++)
        {
            ans+='/';
            ans+=to_string(nums[i]);
        }
        return ans+')';
    }
};

int main()
{
    Solution slv;
    vector<int> nums = 
    // {100,100,123,12};
    {2,3};
    string ans = slv.optimalDivision(nums);
    cout<<ans;
    return 0;
}