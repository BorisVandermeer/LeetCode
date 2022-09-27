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
void showvec(vector<T> vec,int D1Type=1,int D0Type = 3)
{
    if(D0Type = 2) for(auto & a:vec) cout<<a<<", ";
    else if(D0Type = 3) for(auto & a:vec) cout<<a<<' ';
    else for(auto & a:vec) cout<<a;
    if(D1Type==1) cout<<endl;
    if(D1Type==2) cout<<", ";
    if(D1Type==3) cout<<" ";
}

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.length()!= s2.size()) return false;
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return s1==s2;
    }
};



int main()
{
    Solution slv;
    string s1 = "abc";
    string s2 = "bac";
    auto ans = slv.CheckPermutation(s1,s2);
    cout<<ans<<endl;
    return 0;
}