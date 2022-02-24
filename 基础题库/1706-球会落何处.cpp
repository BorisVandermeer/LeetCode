#include<iostream>
#include<vector>

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
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size());
        for(int i=0;i<ans.size();i++) ans[i] = i;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<ans.size();j++)
            {
                if(ans[j]==-1) continue;
                if(grid[i][ans[j]]==1)
                {
                    if(ans[j]==ans.size()-1||grid[i][ans[j]+1]==-1)
                    {
                        ans[j] = -1;
                    }
                    else ans[j]++;
                }
                else
                {
                    if(ans[j]==0||grid[i][ans[j]-1]==1)
                    {
                        ans[j] = -1;
                    }
                    else ans[j]--;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution slv;
    string Input = 
    "[[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]";
    vector<vector<int>> grid = str2vec2I(Input);
    showvec2(grid);
    vector<int> ans = slv.findBall(grid);
    showvec(ans);
    return 0;
}