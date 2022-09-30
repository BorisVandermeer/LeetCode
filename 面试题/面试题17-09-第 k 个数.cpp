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
    int getKthMagicNumber(int k) {
        vector<unsigned int> result(k,INT32_MAX);
        result[0] = 1;
        for(int i=1;i<k;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(result[j]*3>result[i-1]&&result[j]*3<result[i]) result[i] = result[j]*3;
                if(result[j]*5>result[i-1]&&result[j]*5<result[i]) result[i] = result[j]*5;
                if(result[j]*7>result[i-1]&&result[j]*7<result[i]) result[i] = result[j]*7;
                if(result[j]*7<=result[i-1]) break;
            }
        }
        return result[k-1];
    }
};

class Solution_answer {
public:
    int getKthMagicNumber(int k) {
        vector<int> dp(k + 1);
        dp[1] = 1;
        int p3 = 1, p5 = 1, p7 = 1;
        for (int i = 2; i <= k; i++) {
            int num3 = dp[p3] * 3, num5 = dp[p5] * 5, num7 = dp[p7] * 7;
            dp[i] = min(min(num3, num5), num7);
            if (dp[i] == num3) {
                p3++;
            }
            if (dp[i] == num5) {
                p5++;
            }
            if (dp[i] == num7) {
                p7++;
            }
        }
        return dp[k];
    }
};


int main()
{
    Solution slv;

    auto ans = slv.getKthMagicNumber(5);
    cout<<ans<<endl;
    return 0;
}