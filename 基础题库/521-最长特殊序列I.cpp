#include<iostream>
#include<vector>
#include<string>
#include<utility>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a.size()<b.size()) return b.size();
        if(a.size()>b.size()) return a.size();
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i]) return a.size();
        }
        return -1;
    }
};

int main()
{
    Solution slv;
    pair<string,string> Input =
    {"aba","cdc"};
    string & a = Input.first; 
    string & b = Input.second;
    int ans = slv.findLUSlength(a,b);
    cout<<ans;
    return 0;
}