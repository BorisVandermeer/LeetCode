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
    string reformatNumber(string number) {
        string buffer;
        string ans;
        for(auto c : number)
        {
            if(c<'0'||c>'9') continue;
            if(buffer.size()<4)
            {
                buffer.push_back(c);
            }
            else
            {
                if(ans.size()!=0) ans.push_back('-');
                ans.push_back(buffer[0]);
                ans.push_back(buffer[1]);
                ans.push_back(buffer[2]);
                char tmp = buffer[3];
                buffer.resize(2);
                buffer[0] = tmp;
                buffer[1] = c;
            }
        }
        if(ans.size()!=0) ans.push_back('-');
        switch(buffer.size())
        {
            case 2:
                ans.push_back(buffer[0]);
                ans.push_back(buffer[1]);
                break;
            case 3:
                ans.push_back(buffer[0]);
                ans.push_back(buffer[1]);
                ans.push_back(buffer[2]);
                break;
            case 4:
                ans.push_back(buffer[0]);
                ans.push_back(buffer[1]);
                ans.push_back('-');
                ans.push_back(buffer[2]);
                ans.push_back(buffer[3]);
                break;
        }
        return ans;
    }
};
int main()
{
    Solution slv;
    string str;
    str = "123 4-567";
    str = "123 4-5678";
    str = "--17-5 229 35-39475 ";

    auto ans = slv.reformatNumber(str);
    cout<<ans;
    return 0;
}