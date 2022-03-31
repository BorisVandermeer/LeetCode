#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<utility>
#include<map>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool isSelfDividing(int num) {
        int temp = num;
        while (temp > 0) {
            int digit = temp % 10;
            if (digit == 0 || num % digit != 0) {
                return false;
            }
            temp /= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            if (isSelfDividing(i)) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};


int main()
{
    Solution slv;

    auto ans = slv.selfDividingNumbers(47,67);
    // cout<<ans;
    return 0;
}