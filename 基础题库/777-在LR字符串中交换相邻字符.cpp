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
    bool canTransform(string start, string end) {
        // if(start.size()!=end.size()) return false;
        int s_idx = 0;
        int e_idx = 0;
        int size = start.size();
        while(1)
        {
            // 找到下一个R或者L
            while(start[s_idx]=='X') s_idx++;
            while(end  [e_idx]=='X') e_idx++;
            // cout<<s_idx<<' '<<e_idx<<endl;
            if(s_idx == size && e_idx ==s_idx) return true;
            if(s_idx == size || e_idx == size) return false;
            if(start[s_idx]!=end[e_idx]) return false;
            if(s_idx>e_idx&&start[s_idx]=='R') return false;
            if(s_idx<e_idx&&start[s_idx]=='L') return false;
            s_idx++;e_idx++;
            
        }
        return false;
    }
};

int main()
{
    Solution slv;

    pair<string,string> input;
    input = {"LXXLXRLXXL","XLLXRXLXLX"};

    auto ans = slv.canTransform(input.first,input.second);
    cout<<ans;
    return 0;
}