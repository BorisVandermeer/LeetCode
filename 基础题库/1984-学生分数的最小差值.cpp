#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template<typename T=int>
void showvec(vector<T> vec,int flag=1)
{
    for(auto & a:vec) cout<<' '<<a;
    if(flag==1) cout<<endl;
    if(flag==2) cout<<", ";
}

class Solution_SB {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k==1) return 0;
        sort(nums.begin(),nums.end());
        vector<int> dnums(nums.size()-1);
        
        for(int i=1;i<nums.size();i++)
        {
            dnums[i-1] = nums[i]-nums[i-1];
        }
        showvec(dnums);
        int sum=0;
        for(int i=0;i<k-1;i++)
        {
            sum+=dnums[i];
        }
        
        int min = sum;
        for(int i=0;i<nums.size()-k;i++)
        {
            sum-=dnums[i];
            sum+=dnums[k-1+i];
            if(min>sum) min=sum; 
            cout<<sum;
        }
        
        return min;
    }
};

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k==1) return 0;
        sort(nums.begin(),nums.end());
        int n=nums.size()-k+1;
        int min = nums[k-1]-nums[0];
        for(int i=1;i<n;i++)
        {
            min = std::min(nums[k-1+i]-nums[i],min);
            cout<<nums[k-1+i]-nums[i]<<' ';
        }
        
        return min;
    }
};
int main()
{
    Solution slv;
    vector<int> nums = 
    {9,4,1,7};
    int ans = slv.minimumDifference(nums,2);

    return ans;
}