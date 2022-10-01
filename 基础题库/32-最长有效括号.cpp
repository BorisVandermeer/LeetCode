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


template<typename T=int>
void showvec(vector<T> vec,int D1Type=1,int D0Type = 3)
{
    if(D0Type = 2) for(auto & a:vec) cout<<a<<", ";
    else if(D0Type = 3) for(auto & a:vec) cout<<a<<' ';
    else for(auto & a:vec) cout<<a;
    if(D1Type==1) cout<<endl;
    if(D1Type==2) cout<<", ";
    if(D1Type==3) cout<<" ";
}

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(),0);
        int leftcnt = 0;
        int ans = 0;
        for(int i=1;i<s.size();i++)
        {
            if(s[i] == ')')
            {
                if(s[i-1] == '(')
                {
                    if(i>=2) dp[i] = dp[i-2]+2;
                    else dp[i] = 2;
                }
                else
                {
                    if(dp[i-1]==0) continue;
                    if(i>dp[i-1]&&s[i-dp[i-1]-1]=='(')
                    {
                        if(i-dp[i-1]>2) dp[i] = dp[i-1]+2+dp[i-dp[i-1]-2];
                        else dp[i] = dp[i-1]+2;
                    }
                }
                if(dp[i]>ans) ans = dp[i];
            }
        }
        return ans;
    }
};

int main()
{
    Solution slv;
    string s = 
        // ")()())"
        // "(()"
        "()(())"
    ;

    auto ans = slv.longestValidParentheses(s);
    cout<<ans;
    return 0;
}