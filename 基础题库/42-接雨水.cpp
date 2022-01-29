#include<iostream>
#include<vector>

using namespace std;

template<typename T>
void show_vec(vector<T> vec)
{
    for(auto i : vec) cout<<i<<endl;
}

// 每次将所有的量砍掉一层，然后找出每一层能够围水的面积
class Solution1 {
public:
    int trap(vector<int>& height) {
        if(height.size()<3) return 0;
        return 1;


    }
};

// 双向的动态规划_内存很好，速度很慢
class Solution2 {
public:
    int trap(vector<int>& height) {
        if(height.size()<3) return 0;
        int V = 0;
        int right_idx = height.size()-1;
        int left_idx = 0;
        int block_flag = 0;
        cout<<" left_idx : "<<left_idx<<"; right_idx : "<<right_idx<<endl;
        //从左边起点开始查找一个比不小于它的，如果搜到了left，按left来,最后左边将移动到最高点
        while(1)
        {
            int i;
            for(i = left_idx+1;i<right_idx&&height[i]<height[left_idx];i++);
            if(height[left_idx]<=height[i])
            {
                V += (i-left_idx-1)*height[left_idx];
                for(int j = left_idx+1;j<i;j++) V -= height[j];
                left_idx = i;
            }
            for(i = right_idx-1;i>left_idx&&height[i]<height[right_idx];i--);
            if(height[right_idx]<=height[i])
            {
                V += (right_idx-i-1)*height[right_idx];
                for(int j = right_idx-1;j>i;j--) V -= height[j];
                right_idx = i;
            }
            cout<<" left_idx : "<<left_idx<<"; right_idx : "<<right_idx<<endl;
            if(left_idx>=right_idx) return V;
        }
        return -1;
    }
};

// Solution3 双向的动态规划_加入block flag 优化速度，速度和内存都可以了
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<3) return 0;
        int V = 0;
        int right_idx = height.size()-1;
        int left_idx = 0;
        int block_flag = 0;
        cout<<" left_idx : "<<left_idx<<"; right_idx : "<<right_idx<<endl;
        //从左边起点开始查找一个比不小于它的，如果搜到了left，按left来,最后左边将移动到最高点
        while(1)
        {
            int i;
            if(block_flag != -1)
            {
                for(i = left_idx+1;i<right_idx&&height[i]<height[left_idx];i++);
                if(height[left_idx]<=height[i])
                {
                    V += (i-left_idx-1)*height[left_idx];
                    for(int j = left_idx+1;j<i;j++) V -= height[j];
                    left_idx = i;
                }
                if(i==right_idx) block_flag = -1;
            }
            if(block_flag != 1)
            {
                for(i = right_idx-1;i>left_idx&&height[i]<height[right_idx];i--);
                if(height[right_idx]<=height[i])
                {
                    V += (right_idx-i-1)*height[right_idx];
                    for(int j = right_idx-1;j>i;j--) V -= height[j];
                    right_idx = i;
                }
                if(i==left_idx) block_flag = 1;
            }
            cout<<" left_idx : "<<left_idx<<"; right_idx : "<<right_idx<<endl;
            if(left_idx>=right_idx) return V;
        }
        return -1;
    }
};


int main()
{
    Solution slv;
    vector<int> vec = {2,3,4,1,6,6,6,1,0,1};
    return slv.trap(vec);
}