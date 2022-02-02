#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1) return strs[0];
        string ans;
        int idx = -1;
        // char t = strs[0][idx];
        // if(t=='\0') return ans;
        // for(auto & str:strs) if(str[idx]!=t) return ans;
        // ans+=t;
        while(1)
        {
            idx++;
            char t = strs[0][idx];
            if(t=='\0') return ans;
            for(auto & str:strs) if(str[idx]!=t) return ans;
            ans+=t;
        }
        return ans;
    }
};

int main()
{
    Solution slv;
    vector<string> strs = 
    // {
    //     "flower",
    //     "flow",
    //     "flight"
    // };
    {
        " 1",
        " 1"
    };
    string ans = slv.longestCommonPrefix(strs);
    cout<<ans<<endl;
}