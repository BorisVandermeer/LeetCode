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
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n=strs[0].length();
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            char cur = strs[0][i];
            for(int j=1;j<m;j++)
            {
                if(strs[j][i]<cur)
                {
                    cnt++;
                    break;
                }
                cur = strs[j][i];
            }
        }
        return cnt;
    }
};


int main()
{
    Solution slv;
    vector<string> strs = 
    // {"zyx","wvu","tsr"};
    // {"cba","daf","ghi"};
    {"rrjk","furt","guzm"};

    auto ans = slv.minDeletionSize(strs);
    cout<<ans;
    return 0;
}