#include<iostream>
#include<vector>

using namespace std;

// 找出里面最大的字数组和和最小的字数组合，比较（最大字数组）和与（总和-最小子数组和）
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum1 = 0;int sum2 = 0;int sum = 0;
        int max = INT32_MIN;int min = INT32_MAX;
        for(auto & num:nums)
        {            
            sum+=num;
            sum1=sum1>0?sum1+num:num;
            sum2=sum2<0?sum2+num:num;
            cout<<sum1<<' '<<sum2<<endl;
            if(sum1>max) max = sum1;
            if(sum2<min) min = sum2; 
        }
        if(max<0) return max;
        int tmp = sum-min;
        return tmp>max?tmp:max;
    }
};

int main()
{
    Solution slv;
    vector<int> nums=
    {5,-3,5};
    auto ans = slv.maxSubarraySumCircular(nums);
    cout<<endl<<"ANS : "<< ans;
    return 0;
}