#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int min_height = 0;
        int i = 0;int j = height.size()-1;
        while(i!=j)
        {
            int cur;
            if(height[i]<height[j])
            {
                cur = height[i]*(j-i);
                if(min_height<height[i]) min_height=height[i];
                while(height[i]<=min_height&&i!=j) i++;
            }
            else
            {
                cur = height[j]*(j-i);
                if(min_height<height[j]) min_height=height[j];
                while(height[j]<=min_height&&i!=j) j--;
            }
            cout<<"i:"<<i<<"; j:"<<j<<"; cur:"<<cur<<endl;
            if(cur>ans) ans = cur;
        }
        return ans;
    }
};

int main()
{
    //vector<int> a= {1,8,6,2,5,4,8,3,7};
    vector<int> a= {4,3,2,1,4};
    Solution slv;
    return slv.maxArea(a);
}