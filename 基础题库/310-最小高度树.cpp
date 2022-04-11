#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<utility>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<memory>

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

template<typename T=int>
void showvec2(vector<vector<T>> vec,int D2Type = 1,int D1Type=1)
{
    for(auto & a:vec) showvec<T>(a,D1Type);
    if(D2Type==1) cout<<endl;
}

// 没有调试
template<typename T=int>
void showvec3(vector<vector<vector<T>>> vec,int D3Type=1,int D1Type=3)
{
    for(auto b:vec) for(auto & a:b) showvec<T>(a,1,D1Type);
    if(D3Type ==1) cout<<endl;
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

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> map(n);
        vector<int> ans;
        for(auto & edge:edges)
        {
            map[edge[0]].push_back(edge[1]);
            map[edge[1]].push_back(edge[0]);
        }
        vector<int> parent(n,-1);
        queue<int> q;
        parent[0] = 0;
        q.push(0);
        // 找到距离0号节点最远的一个结点
        int cur = 0;
        while(!q.empty())
        {
            cur = q.front();
            q.pop();
            for(auto & node : map[cur])
            {
                if(node!=parent[cur])
                {
                    q.push(node);
                    parent[node] = cur;
                }
            }
        }
        
        // 找到距离cur最远的一条路
        for(auto & node:parent) node = -1;
        int tar = cur;
        q.push(tar);
        parent[cur] = cur;
        while(!q.empty())
        {
            tar = q.front();
            q.pop();
            for(auto & node : map[tar])
            {
                if(node!=parent[tar])
                {
                    q.push(node);
                    parent[node] = tar;
                }
            }
        }

        // 回溯出path
        vector<int> path;
        while(tar!=cur)
        {
            path.push_back(tar);
            tar = parent[tar];
        }
        path.push_back(cur);

        
        ans.push_back(path[path.size()/2]);
        
        if(path.size()%2 == 0)
        {
            ans.push_back(path[path.size()/2-1]);
        }

        return ans;
    }
};

int main()
{
    Solution slv;
    int n = 4;
    vector<vector<int>> edges = str2vec2I("[[1,0],[1,2],[1,3]]");
    auto ans = slv.findMinHeightTrees(n,edges);
    showvec(ans);
    return 0;
}