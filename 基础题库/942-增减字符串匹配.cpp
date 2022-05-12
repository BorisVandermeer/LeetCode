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
    vector<int> diStringMatch(string s) {
        vector<int> ans(s.length()+1);
        int cnt = 1;
        int curidx = -1;
        for(auto chr:s)
        {
            if(chr=='D')
            {
                cnt++;
            }
            else
            {
                for(int j=1;j<=cnt;j++)
                {
                    ans[curidx+j]=curidx+1+cnt-j;
                }
                curidx += cnt;
                cnt = 1;
            }
        }
        for(int j=1;j<=cnt;j++)
        {
            ans[curidx+j]=curidx+1+cnt-j;
        }
        return ans;
    }
};



int main()
{
    Solution slv;

    auto ans = slv.diStringMatch("IDID");
    showvec(ans);
    return 0;
}