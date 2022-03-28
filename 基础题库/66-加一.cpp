#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<utility>
#include<map>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.front()==0) return{1};
        int last_idx=-1;//非9的最后一个位置
        for(int i=digits.size()-1;i>=0;i--) if(digits[i]!=9)
        {
            last_idx = i;
            break;
        }
        if(last_idx==-1)
        {
            vector<int> ans(digits.size()+1,0);
            ans[0] = 1;
            return ans;
        }
        digits[last_idx] ++;
        for(int i = last_idx+1; i<digits.size();i++)
        {
            digits[i] = 0;
        }
        return digits;
    }
};


// int main()
// {
//     Solution slv;

//     auto ans = slv
//     // cout<<ans;
//     return 0;
// }