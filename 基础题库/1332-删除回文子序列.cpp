#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        int cnta = 0;
        int cntb = 0;
        int len = s.length();
        if(len==0) return 0;
        for(int i = 0;i<len/2;i++)
        {
            if(s[i]!=s[len-i-1]) return 2;
        }
        return 1;
    }
};

int main()
{
    Solution slv;
    string str = "";
    return slv.removePalindromeSub(str);
}