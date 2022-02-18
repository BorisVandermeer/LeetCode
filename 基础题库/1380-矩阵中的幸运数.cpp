#include<iostream>
#include<vector>

using namespace std;

template<typename T=int>
void showvec(vector<T> vec,int flag=1)
{
    for(auto & a:vec) cout<<' '<<a;
    if(flag==1) cout<<endl;
    if(flag==2) cout<<", ";
}

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
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        for(int i=0;i<matrix.size();i++)
        {
            int min_idx=0;
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]<matrix[i][min_idx])
                {
                    min_idx = j;
                }
            }
            int flag = 1;
            for(int j=0;j<matrix.size();j++)
            {
                if(matrix[j][min_idx]>matrix[i][min_idx])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag) ans.push_back(matrix[i][min_idx]);
        }
        return ans;
    }
};

int main()
{
    Solution slv;
    vector<vector<int>> matrix 
    // = str2vec2I("[[3,7,8],[9,11,13],[15,16,17]]");
    = str2vec2I("[[1,10,4,2],[9,3,8,7],[15,16,17,12]]");
    vector<int> ans = slv.luckyNumbers(matrix);
    showvec(ans);
    return 0;
}