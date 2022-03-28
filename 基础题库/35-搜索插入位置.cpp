#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<utility>
#include<map>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0;int end = nums.size()-1;
        if(nums.back()<target) return nums.size();
        if(nums.back()==target) return nums.size()-1;
        if(nums.front()>=target) return 0;
        while(begin < end-1)
        {
            int cur_idx = (begin+end)/2;
            if(nums[cur_idx]==target) return cur_idx;
            if(nums[cur_idx]>=target) end = cur_idx;
            else begin = cur_idx;
        }
        return end;
    }
};


// int main()
// {
//     Solution slv;

//     auto ans = slv
//     // cout<<ans;
//     return 0;
// }