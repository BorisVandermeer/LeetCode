#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

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
    unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        // vector<int> nums;
        // for(auto ch:digits)
        // {
        //     nums.push_back(phoneMap[ch].size()-1);
        // }
        vector<string> stack1;
        vector<string> stack2;
        string & str = phoneMap[digits.back()];
        for(int i=str.size()-1;i>=0;i--)
        {
            stack1.push_back(string()+str[i]);
        }
        // return stack1;
        int flag = 1;
        for(int i = digits.size()-2;i>=0;i--)
        {
            string & strtmp = phoneMap[digits[i]];
            if(flag==1)
            {
                flag=2;
                stack2.clear();
                for(int j=strtmp.size()-1;j>=0;j--)
                {
                    
                    for(int k = stack1.size()-1;k>=0;k--)
                    {
                        stack2.push_back(string()+strtmp[j]+stack1[k]);
                    }
                    
                }
            }
            else
            {
                flag=1;
                stack1.clear();
                for(int j=strtmp.size()-1;j>=0;j--)
                {
                    for(int k = stack2.size()-1;k>=0;k--)
                    {
                        stack1.push_back(string()+strtmp[j]+stack2[k]);
                    }
                }
                // showvec<string>(ans,1,3);
            }
            
        }
        if(flag == 1) return stack1;
        return stack2;
    }
};

int main()
{
    Solution slv;
    string digits = 
    "234";
    vector<string> ans = slv.letterCombinations(digits);
    showvec<string>(ans,1,3);
    return 0;
}