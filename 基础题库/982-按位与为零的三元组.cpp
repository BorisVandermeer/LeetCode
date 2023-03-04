#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<utility>
#include<stack>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<set>
#include<unordered_set>
#include<string.h>


using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& nums) {
        vector<int> cnt(65536U,0);
        int ans = 0;
        for(auto num1:nums)
        {
            for(auto num2:nums)
            {
                cnt[num1&num2]++;
            }
        }
        for(auto num:nums)
        {
            for(int i = 65535;i>=0;i--)
            {
                if((num&i)==0)
                {
                    ans+=cnt[i];
                }
            }
        }
        return ans;
    }
};


int main()
{
    Solution slv;
    vector<int> nums = 
    {1,2,3};
    auto ans = slv.countTriplets(nums);
    cout<<ans;
    return 0;
}