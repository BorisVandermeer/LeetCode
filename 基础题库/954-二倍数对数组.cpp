#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<utility>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<memory>

using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> cnt;
        for (int x : arr)  cnt[x]++;
        if (cnt[0] % 2) return 0;

        vector<int> vals;
        vals.reserve(cnt.size());
        for (auto t : cnt) {
            vals.push_back(t.first);
        }
        sort(vals.begin(), vals.end(), [](int a, int b) { return abs(a) < abs(b); });

        for (int x : vals) {
            if (cnt[2 * x] < cnt[x]) { // 无法找到足够的 2x 与 x 配对
                return false;
            }
            cnt[2 * x] -= cnt[x];
        }
        return true;
    }
};

int main()
{
    Solution slv;
    vector<int> arr = 
    {3,1,3,6};
    // {2,1,2,6};
    // {-2,4,-4,2};
    auto ans = slv.canReorderDoubled(arr);
    // cout<<ans;
    return 0;
}