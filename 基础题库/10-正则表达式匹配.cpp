#include<string>
#include<iostream>
#include<vector>

using namespace std;

//递归，但是好像不是很快
class Solution {
    bool matchans(string & s,int poss,string & p,int posp)
    {
        cout<<poss<<' '<<posp<<endl;
        if(poss==s.size()&&posp==p.size()) return true;
        if(posp==p.size()) return false;

        if(posp<p.size()-1&&p[posp+1]=='*')
        {
            cout<<"matching \""<<s.substr(0,poss+1)<<"\" with \""<<p.substr(0,posp+2)<<"\" case 1"<<endl;
            if(poss==s.size()) return(matchans(s,poss,p,posp+2));
            if(p[posp]=='.'||p[posp]==s[poss])
            {
                return matchans(s,poss+1,p,posp)||matchans(s,poss,p,posp+2);
            }
            return matchans(s,poss,p,posp+2);
        }
        if(poss==s.size()) return false;
        cout<<"matching \""<<s.substr(0,poss+1)<<"\" with \""<<p.substr(0,posp+1)<<"\" case 2"<<endl;
        if(p[posp]=='.'||p[posp]==s[poss]) return matchans(s,poss+1,p,posp+1);
        return false;
    }
public:
    bool isMatch(string & s, string & p) {
        return matchans(s,0,p,0);
    }
};

// 使用动态规划，但是实际上也使用了递归。。
class Solution_KEY {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};

int main()
{
    Solution slv;
    vector<string> Input = 
    // {"aa","a"};
    // {"ab","."};
    // {"abcdasd",".*sd"};
    // {"mississippi","mis*is*p*."};
    // {"bbbba",".*a*."};
    {"aabcbcbcaccbcaabc",".*a*aa*.*b*.c*.*a*"};
    string & s = Input[0];
    string & p = Input[1];
    int ans = slv.isMatch(s,p);
    cout<<ans;
    return 0;
    
}