#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<utility>
#include<stack>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<string.h>


using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n1 = 0;
        int n2 = nums.size()-1;
        if(nums[n1]==target) return n1;
        if(nums[n2]==target) return n2;
        int flag = nums[0]>target; 
        while(1)
        {
            int mid = (n1+n2)/2;
            // cout<<n1<<' '<<n2<<' '<<mid<<endl;
            if(mid == n1) break;
            if(nums[mid] == target) return mid;
            if(nums[mid]>nums[0]) //这代表这个mid在前半段
            {
                if(target>nums[mid]||(nums.back()<nums[0]&&target<nums.back())) n1 = mid;
                else n2 = mid;
            }
            else // 这个mid在后半段
            {
                if(target<nums[mid]||(nums.back()<nums[0]&&target>nums.back())) n2 = mid;
                else n1 = mid;
            }
        }
        if(nums[n1]==target) return n1;
        if(nums[n2]==target) return n2;
        return -1;
    }
};



int main()
{
    Solution slv;
    vector<int> nums = {4,5,6,7,0,1,2};

    auto ans = slv.search(nums,7);
    cout<<ans;
    return 0;
}