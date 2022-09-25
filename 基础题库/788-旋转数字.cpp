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

// 我的解法
class Solution {

    // vector<unsigned char> num = {1};
    vector<unsigned int> num = {1};
    vector<unsigned char> target;
    int cnt018 = 1;
    void plusplus()
    {
        int cur_idx = 0;
        while(1)
        {
            if(cur_idx == num.size())
            {
                num.push_back(1);
                cnt018++;
                break;
            }
            else if(num[cur_idx]==9)
            {
                num[cur_idx] = 0;
                cur_idx++;
                cnt018++;
                continue;
            }
            if(num[cur_idx]==0) num[cur_idx]=1;
            else if(num[cur_idx]==1) {num[cur_idx]=2;cnt018--;}
            else if(num[cur_idx]==2) num[cur_idx]=5;
            else if(num[cur_idx]==5) num[cur_idx]=6;
            else if(num[cur_idx]==6) {num[cur_idx]=8;cnt018++;}
            else if(num[cur_idx]==8) {num[cur_idx]=9;cnt018--;}
            break;
        }
    }

    bool compare()
    {
        if(num.size()<target.size()) return true;
        if(num.size()>target.size()) return false;
        for(int i=num.size()-1;i>=0;i--)
        {
            if(num[i]<target[i]) return true;
            if(num[i]>target[i]) return false;
        }
        return true;
    }

public:
    int rotatedDigits(int n) {
        // num.clear();
        if(n==0) return 0;

        while(n)
        {
            target.push_back(n%10);
            n=n/10;
        }
        int ans = 0;
        while(compare())
        {
            if(cnt018!=num.size()) ans++;
            plusplus();
        }
        
        return ans;
    }
};

class Solution_leetcode {
public:
    int rotatedDigits(int n) {
        vector<int> digits;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        reverse(digits.begin(), digits.end());
        
        memset(memo, -1, sizeof(memo));
        function<int(int, bool, bool)> dfs = [&](int pos, bool bound, bool diff) -> int {
            if (pos == digits.size()) {
                return diff;
            }
            if (memo[pos][bound][diff] != -1) {
                return memo[pos][bound][diff];
            }

            int ret = 0;
            for (int i = 0; i <= (bound ? digits[pos] : 9); ++i) {
                if (check[i] != -1) {
                    ret += dfs(
                        pos + 1,
                        bound && (i == digits[pos]),
                        diff || (check[i] == 1)
                    );
                }
            }
            return memo[pos][bound][diff] = ret;
        };
        
        int ans = dfs(0, true, false);
        return ans;
    }

private:
    static constexpr int check[10] = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};
    int memo[5][2][2];
};

int main()
{
    Solution slv;

    auto ans = slv.rotatedDigits(9);
    cout<<ans;
    return 0;
}