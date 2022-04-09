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
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};

int main()
{
    Solution slv;
    string s1 = "abcde";
    string s2 = "cdeab";
    auto ans = slv.rotateString(s1,s2);
    // cout<<ans;
    return 0;
}