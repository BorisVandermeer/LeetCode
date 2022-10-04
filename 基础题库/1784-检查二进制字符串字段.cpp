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
    bool checkOnesSegment(string s) {
        int flag = 0;
        for(int i =0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                flag++;
                while(i<s.size()&&s[i]=='1') i++;
            }
            if(flag > 1) return false; 
        }
        return true;
    }
};

int main()
{
    Solution slv;
    string s = "1001";

    auto ans = slv.checkOnesSegment(s);
    cout<<ans;
    return 0;
}