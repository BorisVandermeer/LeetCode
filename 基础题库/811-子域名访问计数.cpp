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

template<typename T=int>
void showvec(vector<T> vec,char Char0=' ', char CharEnd = '\n')
{
    for(auto & a:vec) cout<<a<<Char0;
    cout<<CharEnd;
}


class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> counts;
        for(auto & str:cpdomains)
        {
            int cnt = 0;
            for(auto & c:str)
            {
                if(c==' ') break;
                cnt = cnt*10+c-'0';
            }
            for(int i=str.size()-1;i>=0;i--)
            {
                if(str[i]=='.')
                {
                    counts[str.substr(i+1)]+=cnt;
                }
                if(str[i]==' ')
                {
                    counts[str.substr(i+1)]+=cnt;
                    break;
                }
            }
        }
        vector<string> ans;
        for(auto && [p,q]:counts)
        {
            string tmpstr;
            while(q)
            {
                tmpstr.push_back(q%10+'0');
                q = q/10;
            }
            reverse(tmpstr.begin(),tmpstr.end());
            tmpstr.push_back(' ');
            tmpstr+=p;
            ans.push_back(tmpstr);
        }
        return ans;
        
    }
};

int main()
{
    Solution slv;
    vector<string> input = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};

    auto ans = slv.subdomainVisits(input);
    showvec(ans,' ','\n');
    return 0;
}