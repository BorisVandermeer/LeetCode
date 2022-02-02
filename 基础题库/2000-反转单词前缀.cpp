#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx=0;
        for(auto & c:word)
        {
            if(c==ch) break;
            idx++;
        }
        if(idx==word.size()) return word;
        int m = (idx+1)/2;
        for(int i=0;i<m;i++)
        {
            char t;
            t = word[i];
            word[i]=word[idx-i];
            word[idx-i] = t;
        }
        return word;
    }
};

int main()
{
    Solution slv;
    string word = "qwe";
    char ch = 'd';
    auto ans = slv.reversePrefix(word,ch);
    cout<<ans<<endl;
    return 1;
}