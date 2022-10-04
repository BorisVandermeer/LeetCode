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
    int minAddToMakeValid(string s) {
        int ans = 0;
        int cnt = 0;

        for(auto c : s)
        {
            if(c=='(')
            {
                cnt++;
            }
            else if(cnt == 0) ans++;
            else cnt--;
        }
        return ans+cnt;

    }
};

int main()
{
    Solution slv;

    auto ans = slv.minAddToMakeValid("())");
    cout<<ans;
    return 0;
}