#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        int pos1 = 0;
        int pos2 = 1;
        while(pos2<nums.size())
        {
            if(nums[pos2]<nums[pos1])
            {
                pos1 = pos2;
                pos2++;
            }
            else
            {
                if(nums[pos2]-nums[pos1]>ans)
                {
                    ans = nums[pos2]-nums[pos1];
                }
                pos2++;
            }
        }
        if(ans==0) return -1;
        return ans;
    }
};

class Solution_faster {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int res = -1e8;
        for (int i = 1, minv = nums[0]; i < n; i++) {
            if (nums[i] > minv) res = max(res, nums[i] - minv);
            minv = min(minv, nums[i]);
        }
        if (res == -1e8) return -1;
        return res;
    }
};

int main()
{
    Solution slv;
    vector<int> nums = 
    // {7,1,5,4};
    // {9,4,3,2};
    // {1,5,2,10};
    {999,997,980,976,948,940,938,928,924,917,907,907,881,878,864,862,859,857,848,840,824,824,824,805,802,798,788,777,775,766,755,748,735,732,727,705,700,697,693,679,676,644,634,624,599,596,588,583,562,558,553,539,537,536,509,491,485,483,454,449,438,425,403,368,345,327,287,285,270,263,255,248,235,234,224,221,201,189,187,183,179,168,155,153,150,144,107,102,102,87,80,57,55,49,48,45,26,26,23,15};
    int ans = slv.maximumDifference(nums);
    cout<<ans;
    return 0;
}