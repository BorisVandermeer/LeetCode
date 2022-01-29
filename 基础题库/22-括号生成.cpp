#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(ans,"",0,0,n);
        return ans;
    }
private:
    void generate(vector<string>& tar,string str,int l,int r,int n)
    {
        if(l>n||r>n||r>l) return;
        else if(l==n&&r==n)
        {
            tar.push_back(str);
            return;
        }
        generate(tar,str+'(',l+1,r,n);
        generate(tar,str+')',l,r+1,n);
    }

};

class Key1 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        func(res, "", 0, 0, n);
        return res;
    }
    
    void func(vector<string> &res, string str, int l, int r, int n){
        if(l > n || r > n || r > l) return ;
        if(l == n && r == n) {res.push_back(str); return;}
        func(res, str + '(', l+1, r, n);
        func(res, str + ')', l, r+1, n);
        return;
    }
};

int main()
{
    Solution slv;
    auto ans = slv.generateParenthesis(8);
    for(auto str:ans)
    {
        cout<<str<<endl;
    }
    return 1;
}