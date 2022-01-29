#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //确保了nums1的长度一定小于nums2
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2, nums1);
        //开始对短的向量进行二分法求解
        int begin = nums1.size();
        int end = nums2.size();
        int cur = (begin+end)/2;
        while(1)
        {
            if(1) return 0;
        }
        return 0;
    }
};

int main()
{
    vector<int> vec1 = {1,3};
    vector<int> vec2 = {2};
    Solution slv;
    double ans = slv.findMedianSortedArrays(vec1,vec2);
    return 0;
}