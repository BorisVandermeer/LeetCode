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
    void nextPermutation(vector<int>& nums) {
        int idx = 0;
        for(int i=nums.size()-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {
                idx = i;
                break;
            }
        }
        if(idx == 0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int tmp = nums[idx-1];
        reverse(nums.begin()+idx,nums.end());
        for(int i = idx;i<nums.size();i++)
        {
            if(nums[i]>nums[idx-1])
            {
                nums[idx-1] = nums[i];
                nums[i] = tmp;
                return;
            }
        }
    }
};

vector<int> str2vecI(string str)
{
    vector<int> ans;
    int flag = 0;
    int flag2 = 1;
    int cur = 0;
    for(auto & ch:str)
    {
        if(ch=='-') flag2 = -1;
        if(flag == 0)
        {
            if(ch>='0'&&ch<='9')
            {
                cur+=(int)(ch-'0');
                flag = 1;
            }
        }
        else
        {
            if(ch>='0'&&ch<='9')
            {
                cur=cur*10+ch-'0';
            }
            else
            {
                flag = 0;
                if(flag2==-1) cur=-cur;
                ans.push_back(cur);
                flag2=1;
                cur=0;
            }
        }
    }
    return ans;
}

int main()
{
    Solution slv;
    vector<int> nums = str2vecI(
        // "[3,2,1]"
        // "[1,5,1,1]"
        "[1,3,2]"
    );

    slv.nextPermutation(nums);
    showvec(nums);
    return 0;
}