#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<utility>
#include<map>
#include<stack>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> m;
        for(auto & op : ops)
        {
            if(op[0]=='C')
            {
                m.pop_back();
            }
            else if(op[0]=='D')
            {
                m.push_back(2*m.back());
            }
            else if(op[0]=='+')
            {
                m.push_back(m.back()+m[m.size()-2]);
            }
            else if(op[0]=='-')
            {
                int tmp = 0;
                for(int i=1;i<op.size();i++)
                {
                    tmp*=10;
                    tmp+=op[i]-'0'; 
                }
                m.emplace_back(-tmp);
            }
            else
            {
                int tmp = 0;
                for(int i=0;i<op.size();i++)
                {
                    tmp*=10;
                    tmp+=op[i]-'0'; 
                }
                m.emplace_back(tmp);
            }
        }
        int ans = 0;
        for(int & t:m) ans+=t;
        return ans;
    }
};


int main()
{
    Solution slv;
    vector<string> ops = {"5","2","C","D","+"};

    auto ans = slv.calPoints(ops);
    cout<<ans;
    return 0;
}