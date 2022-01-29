#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int map[128] = {0};
        int idx_begin = 1;
        int maxlen = 0;
        if(s.length()==0) return 0;
        for(int i=0;i<s.length();i++)
        {
            if(map[(int)s[i]]>=idx_begin)
            {
                if(maxlen<i-idx_begin+1)
                {
                    maxlen = i-idx_begin+1;
                }
                idx_begin = map[(int)s[i]]+1;
            }
            map[(int)s[i]] = i+1;
        }
        cout<<idx_begin<<endl;
        if(maxlen<s.length()-idx_begin+1) maxlen=s.length()-idx_begin+1;
        return maxlen;
    }
};

int main()
{   
    Solution slv;
    string c("abcabcbb");
    cout<<(int)c[0]<<endl<<c.length()<<endl;
    return slv.lengthOfLongestSubstring(c);
}