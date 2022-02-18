#include<vector>
#include<iostream>

using namespace std;

template<typename T=int>
void showvec(vector<T> vec,int D1Type=1,int D0Type = 3)
{
    if(D0Type = 2) for(auto & a:vec) cout<<a<<", ";
    else if(D0Type = 3) for(auto & a:vec) cout<<' '<<a;
    else for(auto & a:vec) cout<<a;
    if(D1Type==1) cout<<endl;
    if(D1Type==2) cout<<", ";
    if(D1Type==3) cout<<" ";
}

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        int i = 0;
        while(i+cnt<nums.size())
        {
            if(nums[i+cnt]==val) cnt++;
            else
            {
                nums[i]=nums[i+cnt];
                i++;
            }
        }
        // for(i=cnt;i>0;i--)
        // {
        //     nums.pop_back();
        // }
        return nums.size()-cnt;
    }
};

int main()
{
    Solution slv;
    vector<int> nums=
    {3,2,2,3};
    int val = 3;
    int ans = slv.removeElement(nums,val);
    showvec(nums);
    cout<<ans;
    return 0;
}