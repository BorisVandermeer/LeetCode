#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int r1 = nums.size()/2; 
        int r2 = 0;
        if(r1==0) return nums[0];
        while(r1!=r2)
        {
            int tmp = (r1+r2)/2*2;
            cout<<r1<<r2<<endl;
            if(nums[tmp]==nums[tmp+1])
            {
                r2=tmp/2+1;
                continue;
            }
            if(tmp==0) return nums[0];
            if(nums[tmp]==nums[tmp-1])
            {
                r1=tmp/2-1;
                continue;
            }
            // cout<<r1<<r2<<endl;
            return nums[tmp];
        }
        return nums[r1*2];
    }
};


class Solution_2 {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int r1 = nums.size()-1; 
        int r2 = 0;
        if(r1==0) return nums[0];
        while(r1!=r2)
        {
            int tmp = (r1+r2)/2;
            if(tmp&1)
            {
                //if(tmp==0) return nums[0];
                if(nums[tmp]==nums[tmp-1]) r2=tmp+1;
                else r1=tmp;
                // cout<<r1<<r2<<endl;
            }
            else
            {
                if(nums[tmp]==nums[tmp+1]) r2=tmp+2;
                else r1=tmp;
            }
        }
        return nums[r1];
    }
};

int main()
{
    Solution_2 slv;
    vector<int> nums = 
    // {3,3,7,7,10,11,11};
    // {1,1,2,3,3,4,4,8,8};
    // {1,1,2};
    {1,2,2,3,3};
    // {0,1,1};
    int ans = slv.singleNonDuplicate(nums);
    cout << ans;
    return 0;
}