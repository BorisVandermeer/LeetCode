#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<utility>
#include<map>
#include<unordered_map>
#include<algorithm>

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

// 1.7s 等于没搞
class Solution_1700ms {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        for(int i = 0;i<intervals.size();i++)
        {
            for(int j =i+1;j<intervals.size();j++)
            {
                if(!(intervals[i][0]>intervals[j][1]||intervals[i][1]<intervals[j][0]))
                {
                    intervals[i][0] = min(intervals[i][0],intervals[j][0]);
                    intervals[i][1] = max(intervals[i][1],intervals[j][1]);
                    intervals[j][0] = intervals[i][0];
                    intervals[j][1] = intervals[i][1];
                }
            }
            while(i!=intervals.size()-1&&!(intervals[i][0]>intervals[i+1][1]||intervals[i][1]<intervals[i+1][0])) i++;
        }
        vector<vector<int>> ans;
        for(int i = intervals.size()-1;i>-1;i--)
        {
            bool flag = true;
            for(int j = 0;j<ans.size();j++)
            {
                if(!(intervals[i][0]>ans[j][1]||intervals[i][1]<ans[j][0]))
                {
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(intervals[i]);
        }
        return ans;
    }
};

// 32ms
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size()==0) return ans;
        sort(intervals.begin(),intervals.end());
        int mi = intervals[0][0];int ma = intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]>ma)
            {
                ans.push_back({mi,ma});
                mi = intervals[i][0];
                ma = intervals[i][1];
            }
            else
            {
                ma = max(intervals[i][1],ma);
            }
        }
        ans.push_back({mi,ma});
        return ans;
    }
};


int main()
{
    Solution slv;
    vector<vector<int>> intervals = 
    // str2vec2I("[[1,3],[2,6],[8,10],[15,18]]");
    // str2vec2I("[[1,4],[4,5]]");
    str2vec2I("[[1,3]]");
    auto ans = slv.merge(intervals);
    showvec2(ans);
    return 0;
}