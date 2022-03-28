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
    bool hasAlternatingBits(int n) {
        int cur = n%2;
        n = n/2;
        while(n)
        {
            if(cur == n%2)return false;
            n=n/2;
            cur = !cur;
        }
        return true;
    }
};


int main()
{
    Solution slv;

    auto ans = slv.hasAlternatingBits(5);
    cout<<ans;
    return 0;
}