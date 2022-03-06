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

// 暴力解法
class Solution_CostTooMuchTime {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> ans;
        if(security.size()<time+time+1) return ans;
        int tmp1 = -1;
        int tmp2 = time;
        int maxi = security.size()-time;
        for(int i=time;i<maxi;i++)
        {
            bool flag = true;
            for(int j=1;j<=time;j++)
            {
                if(security[i-j]<security[i-j+1]||security[i+j]<security[i+j-1])
                {
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(i);
        }
        return ans;
    }
};

//动态规划
class Solution_1{
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> ans;
        if(security.size()<time+time+1) return ans;
        vector<int> map_right(security.size());
        vector<int> map_left(security.size());
        map_right[0]=0;
        map_left[security.size()-1]=0;
        for(int i=1;i<security.size();i++)
        {
            if(security[i]<=security[i-1])
            {
                map_right[i]=map_right[i-1]+1;
            }
            else
            {
                map_right[i]=0;
            }
            if(security[security.size()-i-1]<=security[security.size()-i])
            {
                map_left[security.size()-i-1]=map_left[security.size()-i]+1;
            }
            else
            {
                map_left[security.size()-i-1]=0;
            }
        }
        // showvec(map_right);
        // showvec(map_left);
        int maxi = security.size()-time;
        for(int i=time;i<maxi;i++)
        {
            if(map_right[i]>=time&&map_left[i]>=time) ans.push_back(i);
        }
        return ans;
    }
};
//动态规划
class Solution{
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> ans;
        if(security.size()<time+time+1) return ans;
        vector<int> map_right(security.size(),0);
        vector<int> map_left(security.size(),0);
        map_right[0]=0;
        map_left[security.size()-1]=0;
        for(int i=1;i<security.size();i++)
        {
            if(security[i]<=security[i-1])
            {
                map_right[i]=map_right[i-1]+1;
            }
            if(security[security.size()-i-1]<=security[security.size()-i])
            {
                map_left[security.size()-i-1]=map_left[security.size()-i]+1;
            }
        }
        // showvec(map_right);
        // showvec(map_left);
        int maxi = security.size()-time;
        for(int i=time;i<maxi;i++)
        {
            if(map_right[i]>=time&&map_left[i]>=time) ans.push_back(i);
        }
        return ans;
    }
};

int main()
{
    Solution slv;
    vector<int> security =
    // {5,3,3,3,5,6,2};
    {1,2,5,4,1,0,2,4,5,3,1,2,4,3,2,4,8};
    int time = 2;
    vector<int> ans = slv.goodDaysToRobBank(security,time);
    showvec(ans);
    return 0;
}