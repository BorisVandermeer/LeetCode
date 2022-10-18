#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<utility>
#include<stack>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<set>
#include<unordered_set>
#include<string.h>


using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        const string str1 = "Push";
        const string str2 = "Pop";
        int cur_tidx = 0;
        int cur = 1;
        while(1)
        {
            if(cur == target[cur_tidx])
            {
                cur++;
                cur_tidx++;
                ans.push_back(str1);
                if(cur_tidx==target.size()) return ans;
            }
            else
            {
                cur++;
                ans.push_back(str1);
                ans.push_back(str2);
            }
        }
        return ans;
        
    }
};

int main()
{
    Solution slv;
    vector<int> t = {1,3};

    auto ans = slv.buildArray(t,3);
    // cout<<ans;
    return 0;
}