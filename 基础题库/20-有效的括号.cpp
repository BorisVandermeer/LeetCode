#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.size()==1) return false;
        stack<char> stk;
        for(auto & ch :s)
        {
            if(ch=='('||ch=='['||ch=='{') stk.push(ch);
            else
            {
                if(stk.size()==0) return false;
                char cht = stk.top();
                if(ch==')'&&cht!='(') return false;
                if(ch==']'&&cht!='[') return false;
                if(ch=='}'&&cht!='{') return false;
                stk.pop();
            }
        } 
        if(stk.size()==0) return true;
        return false;
    }
};

int main()
{
    Solution slv;
    string s = 
    "([]{[})]";
    bool ans = slv.isValid(s);
    cout<<ans;
    return 0;
}