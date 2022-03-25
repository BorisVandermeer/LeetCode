#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<utility>
#include<map>
#include<unordered_map>

using namespace std;

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
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans(img.size());
        for(auto & vec:ans) vec.resize(img[0].size());
        int m = img.size();
        int n = img[0].size();
        if(m==1&&n==1) return img;
        if(m==1)
        {
            ans[0][0] = (img[0][0]+img[0][1])/2;
            ans[0][n-1] = (img[0][n-2]+img[0][n-1])/2;
            for(int i = 1;i<n-1;i++)
            {
                ans[0][i] = (img[0][i-1]+img[0][i]+img[0][i+1])/3;
            }
            return ans;
        }
        if(n==1)
        {
            ans[0][0] = (img[0][0]+img[1][0])/2;
            ans[m-1][0] = (img[m-1][0]+img[m-2][0])/2;
            for(int i = 1;i<m-1;i++)
            {
                ans[i][0] = (img[i-1][0]+img[i][0]+img[i+1][0])/3;
            }
            return ans;
        }
        ans[0][0] = (img[0][0]+img[0][1]+img[1][0]+img[1][1])/4;
        ans[0][n-1] = (img[0][n-1]+img[0][n-2]+img[1][n-1]+img[1][n-2])/4;
        ans[m-1][0] = (img[m-1][0]+img[m-1][1]+img[m-2][0]+img[m-2][1])/4;
        ans[m-1][n-1] = (img[m-1][n-1]+img[m-1][n-2]+img[m-2][n-1]+img[m-2][n-2])/4;
        for(int i = 1;i<n-1;i++)
        {
            ans[0][i] = (img[0][i-1]+img[0][i]+img[0][i+1]+img[1][i-1]+img[1][i]+img[1][i+1])/6;
            ans[m-1][i] = (img[m-1][i-1]+img[m-1][i]+img[m-1][i+1]+img[m-2][i-1]+img[m-2][i]+img[m-2][i+1])/6;
        }
        for(int i = 1;i<m-1;i++)
        {
            ans[i][0] = (img[i-1][0]+img[i][0]+img[i+1][0]+img[i-1][1]+img[i][1]+img[i+1][1])/6;
            ans[i][n-1] = (img[i-1][n-1]+img[i][n-1]+img[i+1][n-1]+img[i-1][n-2]+img[i][n-2]+img[i+1][n-2])/6;
        }
        for(int i = 1;i<m-1;i++)
        {
            for(int j = 1;j<n-1;j++)
            {
                ans[i][j] = (img[i-1][j-1]+img[i][j-1]+img[i+1][j-1]+img[i-1][j]+img[i][j]+img[i+1][j]+img[i-1][j+1]+img[i][j+1]+img[i+1][j+1])/9;
            }
        }
        return ans;
    }
};




int main()
{
    Solution slv;
    vector<vector<int>> img = 
    // str2vec2I("[[1,1,1],[1,0,1],[1,1,1]]");
    // str2vec2I("[[100,200,100],[200,50,200],[100,200,100]]");
    str2vec2I("[7][9][6]");
    auto ans = slv.imageSmoother(img);
    showvec2(ans);
    return 0;
}