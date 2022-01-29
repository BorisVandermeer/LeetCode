#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int cur = 0;
        int pre = 0;
        for(int i = 2;i<=cost.size();i++)
        {
            int val = cur;
            cur = min(cur+cost[i-1],pre+cost[i-2]);
            pre = val;
        }
        return cur;
    }
};

int main()
{
    Solution slv;
    vector<int> vec = {1,100,1,1,1,100,1,1,100,1};
    auto ans  = slv.minCostClimbingStairs(vec);
    return ans;
}