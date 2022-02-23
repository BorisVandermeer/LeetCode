#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int pos1 = 0;
        int pos2 = s.length()-1;
        while(pos1<pos2)
        {
            if(!isalpha(s[pos1])) pos1++;
            else if(!isalpha(s[pos2])) pos2--;
            else
            {
                char tmp;
                tmp = s[pos1];s[pos1] = s[pos2];s[pos2]=tmp;
                pos1++;pos2--;
            }
            
        }
        return s;
    }
};

int main()
{
    Solution slv;
    string s = 
    "ab";
    // "j-Ih-gfE-dCba";
    string ans = slv.reverseOnlyLetters(s);
    cout<<ans;
    return 0;
}