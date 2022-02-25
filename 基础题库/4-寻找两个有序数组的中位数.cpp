#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution_Key {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        // median1：前一部分的最大值
        // median2：后一部分的最小值
        int median1 = 0, median2 = 0;

        while (left <= right) {
            // 前一部分包含 nums1[0 .. i-1] 和 nums2[0 .. j-1]
            // 后一部分包含 nums1[i .. m-1] 和 nums2[j .. n-1]
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;

            // nums_im1, nums_i, nums_jm1, nums_j 分别表示 nums1[i-1], nums1[i], nums2[j-1], nums2[j]
            int nums_im1 = (i == 0 ? INT32_MIN : nums1[i - 1]);
            int nums_i = (i == m ? INT32_MAX : nums1[i]);
            int nums_jm1 = (j == 0 ? INT32_MIN : nums2[j - 1]);
            int nums_j = (j == n ? INT32_MAX : nums2[j]);

            if (nums_im1 <= nums_j) {
                median1 = max(nums_im1, nums_jm1);
                median2 = min(nums_i, nums_j);
                left = i + 1;
            } else {
                right = i - 1;
            }
        }
        int i;

        return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3(nums1.size()+nums2.size());
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),nums3.begin());
        double ans;
        if(nums3.size()%2==0) ans = (nums3[nums3.size()/2]+(double)nums3[nums3.size()/2-1])/2;
        else ans = nums3[nums3.size()/2];
        return ans;
    }
};

int main()
{
    Solution slv;
    vector<vector<int>> numss = 
    // {
    //     {1,2,3,4,5,6,7},
    //     {3,4,5,6,7,8,9}
    // };
    {
        {1,2},
        {3,4}
    };
    vector<int> & nums1 = numss[0];
    vector<int> & nums2 = numss[1];
    double ans = slv.findMedianSortedArrays(nums1,nums2);
    cout<<ans;
    return 0;

}



