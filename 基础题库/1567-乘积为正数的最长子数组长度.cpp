#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int i = -1;
        int ans = 0;
        int size = nums.size();
        while(i<size-1)
        {
            int begin = i+1;
            int first = -1;
            int last = -1;
            int cnt = 1;
            i++;
            while(nums[i]!=0)//找一串没有0的数组
            {
                if(nums[i]<0)
                {
                    if(first == -1) first = i;
                    last = i;
                    cnt=!cnt;
                }
                if(i==nums.size()-1) break;
                i++;
            }
            int end = i;
            if(nums[end]==0) end--;
            cout<<"end is : "<<end<<endl;
            if(cnt) // 如果这一串数组内的乘积为正
            {
                if(end-begin+1>ans) ans = end-begin+1;
            }
            else //如果这一段数组的乘积为负
            {
                if(end-first>ans) ans = end-first;
                if(last-begin>ans) ans = last-begin;
            }
        }
        return ans;
    }
};

int main()
{
    Solution slv;
    vector<int> nums = 
    {1,-2,-3,4};
    int ans = slv.getMaxLen(nums);
    cout<<ans;
    return 0;
}