#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<utility>
#include<stack>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<string.h>

using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cur_idx = 0;
        while(1)
        {
            if(s1[cur_idx] != s2[cur_idx]) break;
            if(cur_idx == s1.size()-1) return true;
            cur_idx++;
        }
        if(cur_idx == s1.size()-1) return false;
        int lastidx = cur_idx;
        cur_idx++;
        
        while(1)
        {
            if(s1[cur_idx] != s2[cur_idx])
            {
                if(s1[lastidx] == s2[cur_idx]&&s2[lastidx] == s1[cur_idx]) break;
                return false;
            }
            if(cur_idx == s1.size()-1) return false;
            cur_idx++;
        }
        
        if(cur_idx == s1.size()-1) return true;
        cur_idx++;
        while(1)
        {
            if(s1[cur_idx] != s2[cur_idx]) return false;
            if(cur_idx == s1.size()-1) return true;
            cur_idx++;
        }
        return true;
    }
};

int main()
{
    Solution slv;
    string s1 = "qgqeg";
    string s2 = "gqgeq";

    auto ans = slv.areAlmostEqual(s1,s2);
    return ans;
}