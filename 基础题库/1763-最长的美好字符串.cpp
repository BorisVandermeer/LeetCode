#include<iostream>
#include<string>

using namespace std;

// 遍历掉
class Solution {
public:
    string longestNiceSubstring(string s) {
        int max_pos = 0;
        int max_len = 0;
        for(int i=0;i<s.length();i++) 
        {
            int lower = 0;
            int upper = 0;
            for(int j=i;j<s.length();j++)
            {
                if (islower(s[j])) {
                    lower |= 1 << (s[j] - 'a');
                } else {
                    upper |= 1 << (s[j] - 'A');
                }
                if (lower == upper && j - i + 1 > max_len) {
                    max_pos = i;
                    max_len = j - i + 1;
                }
            }
        }
        string ans(&s[max_pos],&s[max_pos+max_len]);
        return ans;
    }
};

int main()
{
    Solution slv;
    string str = 
        // "YazaAay";
        "UoiasdDAS";
    string s = slv.longestNiceSubstring(str);
    cout<<s<<endl;
    return 0;
}