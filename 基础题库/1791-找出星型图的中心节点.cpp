#include<iostream>
#include<vector>

using namespace std;

vector<int> str2vecI(string str)
{
    vector<int> ans;
    int flag = 0;
    int cur = 0;
    for(auto & ch:str)
    {
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
                ans.push_back(cur);
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

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return edges[0][0]==edges[1][0]||edges[0][0]==edges[1][1]?edges[0][0]:edges[0][1];
    }
};

int main()
{
    Solution slv;
    vector<vector<int>> edges  = 
    str2vec2I("[[1,2],[2,3],[4,2]]");
    int ans = slv.findCenter(edges);
    cout<<ans;
    return 0;
}
