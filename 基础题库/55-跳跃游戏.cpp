#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur = nums.size()-1;
        if(cur==0) return true;
        int i ;
        while(1)
        {
            for(i=cur-1;i>=0&&nums[i]<cur-i;i--);
            if(i==-1) return false;
            if(i==0) return true;
            cur = i;
        }
        return true;
    }
};  


int main()
{
    Solution slv;
    vector<int> vec = {4,2,1,0,4,2,3,1};
    return slv.canJump(vec);
}