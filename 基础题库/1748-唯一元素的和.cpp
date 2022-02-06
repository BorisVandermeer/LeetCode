#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto & num:nums)
        {
            map[num]++;
        }
        int sum=0;
        //for(auto & [num,times]:map) if(times==1) sum+=num; //C++17 NEEDED
        for(auto & it :map) if(it.second==1) sum+=it.first;
        return sum;
    }
};



int main()
{
    Solution slv;
    vector<int> nums=
    {1,2,3,2};
    int ans = slv.sumOfUnique(nums);
    return ans;
}

