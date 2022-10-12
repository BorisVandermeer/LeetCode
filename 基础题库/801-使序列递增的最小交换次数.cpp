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
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int cur_idx = 0;
        int chd = 1;
        int chl = 0;
        for(int i =1;i<nums1.size();i++)
        {
            int & tmp1 = nums1[i];
            int & tmp2 = nums2[i];
            int tmpd = INT32_MAX;
            int tmpl = INT32_MAX;
            if(chl!=INT32_MAX)
            {
                if(tmp1>nums1[i-1]&&tmp2>nums2[i-1]) tmpl = chl;
                if(tmp1>nums2[i-1]&&tmp2>nums1[i-1]) tmpd = chl+1;
            }
            if(chd!=INT32_MAX)
            {
                if(tmp1>nums2[i-1]&&tmp2>nums1[i-1]) if(tmpl>chd) tmpl>chd;
                if(tmp1>nums1[i-1]&&tmp2>nums2[i-1]) if(tmpd>chd+1) tmpd>chd+1;
            }
            chl = tmpl;
            chd = tmpd;
        }
        if(chl>chd) return chd;
        return chl;
    }
};

int main()
{
    Solution slv;
    vector<int> nums1 = {0,3,5,8,9};
    vector<int> nums2 = {2,1,4,6,9};

    auto ans = slv.minSwap(nums1,nums2);
    // cout<<ans;
    return 0;
}