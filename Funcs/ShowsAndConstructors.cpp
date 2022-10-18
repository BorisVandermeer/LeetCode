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
void showvec(vector<T> vec, char CharEnd = '\n',char Char0=' ')
{
    for(auto & a:vec) cout<<a<<Char0;
    cout<<CharEnd;
}

template<typename T=int>
void showvec2(vector<vector<T>> vec,char CharEnd = '\n',char Char1 = '\n',char Char0=' ')
{
    for(auto & a:vec) showvec<T>(a,Char1,Char0);
    cout<<CharEnd;
}

template<typename T=int>
void showvec3(vector<vector<vector<T>>> vec,char CharEnd = '\n',char Char2 = '\n', char Char1 = '\n',char Char0=' ')
{
    for(auto & a:vec) showvec2<T>(a,Char2,Char1,Char0);
    cout<<CharEnd;
}

vector<int> str2vecI(string str)
{
    vector<int> ans;
    int flag = 0;
    int flag2 = 1;
    int cur = 0;
    for(auto & ch:str)
    {
        if(ch=='-') flag2 = -1;
        if(flag == 0)
        {
            if(ch>='0'&&ch<='9')
            {
                cur+=(int)(ch-'0');
                flag = 1;
            }
        }
        else
        {
            if(ch>='0'&&ch<='9')
            {
                cur=cur*10+ch-'0';
            }
            else
            {
                flag = 0;
                if(flag2==-1) cur=-cur;
                ans.push_back(cur);
                flag2=1;
                cur=0;
            }
        }
    }
    return ans;
}

vector<vector<int>> str2vec2I(string str)
{
    vector<vector<int>> ans;
    int flag;
    string str2;
    for(auto & ch:str)
    {
        str2.push_back(ch);
        if(ch==']')
        {
            if(str2.size()==1) return ans;
            vector<int> vec= str2vecI(str2);
            ans.push_back(vec);
            str2.clear();
        }
    }
    return ans;
}