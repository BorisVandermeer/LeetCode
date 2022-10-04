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


template<typename T=int>
void showvec(vector<T> vec,int D1Type=1,int D0Type = 3)
{
    if(D0Type = 2) for(auto & a:vec) cout<<a<<", ";
    else if(D0Type = 3) for(auto & a:vec) cout<<a<<' ';
    else for(auto & a:vec) cout<<a;
    if(D1Type==1) cout<<endl;
    if(D1Type==2) cout<<", ";
    if(D1Type==3) cout<<" ";
}


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int h1=0;int h2=0;
        int t1 = nums.size()-1;
        int t2 = nums.size()-1;
        while(h1<=t1) // 拆分成两个区间，一个只存在第一个，一个只存在后一个
        {
            int mid = (h1+t1)/2;
            if(nums[mid]>target) //这个点依然在后面
            {
                t1 = mid-1;
            }
            else if(nums[mid]<target)
            {
                h1 = mid+1;
            }
            else
            {
                h2 = mid;t2 = t1;
                t1 = mid;
                break;
            }
            
        }
        // cout<<h1<<' '<<t1<<' '<<t2<<endl;
        if(h1>t1) return {-1,-1};
        vector<int> ans(2);
        while(1)
        {
            int mid = (h1+t1)/2;
            if(target - nums[mid]) h1 = mid+1;
            else
            {
                if(mid==h1||nums[mid-1]!=target)
                {
                    ans[0] = mid;
                    break;
                }
                else
                {
                    t1 = mid -1;
                }
            }
        }
        while(1)
        {
            int mid = (h2+t2)/2;
            if(nums[mid]-target) t2 = mid-1;
            else
            {
                if(mid==t2||nums[mid+1]!=target)
                {
                    ans[1] = mid;
                    break;
                }
                else
                {
                    h2 = mid+1;
                }
            }
        }
        return ans;
    
    }
};

int main()
{
    Solution slv;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;

    auto ans = slv.searchRange(nums,target);
    cout<<ans[0]<<' '<<ans[1]<<endl;
    return 0;
}