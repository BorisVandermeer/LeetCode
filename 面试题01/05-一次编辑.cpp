#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<utility>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<memory>

using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        if(first.length()==second.length())
        {
            int flag = 0;
            for(int i=0;i<second.length();i++)
            {
                if(first[i]!=second[i])
                {
                    if(flag) return false;
                    flag = true;
                }
            }
        }
        else if(first.length()==second.length()-1)
        {
            int i=0;
            for(;i<first.length();i++)
            {
                if(first[i]!=second[i]) break;
            }
            for(;i<first.length();i++)
            {
                if(first[i]!=second[i+1]) return false;
            }
        }
        else if(first.length()==second.length()+1)
        {
            int i=0;
            for(;i<second.length();i++)
            {
                if(first[i]!=second[i]) break;
            }
            for(;i<second.length();i++)
            {
                if(first[i+1]!=second[i]) return false;
            }
        }
        else
        {
            return false;
        }
        
        return true;
    }
};

int main()
{
    Solution slv;

    auto ans = slv.oneEditAway("pals","pala");
    cout<<ans;
    return 0;
}