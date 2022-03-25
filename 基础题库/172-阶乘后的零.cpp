#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<utility>
#include<map>
#include<unordered_map>

using namespace std;

// 不断除以5
class Solution_1 {
public:
    int trailingZeroes(int n) {
        int ans=0;
        for(int i=5;i<=n;i++)
        {
            int t = i;
            while(t)
            {
                if(t%5==0)
                {
                    ans++;
                    t = t/5;
                }
                else
                {
                    t=0;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        n/=5;
        while(n)
        {
            ans+=n;
            n/=5;
        }
        return ans;
    }
};

int main()
{
    int n = 1;
    Solution slv;
    int ans = slv.trailingZeroes(25);
    cout<<ans;
    return 0;
}