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

template<typename T=int>
void showvec2(vector<vector<T>> vec,int flag=1)
{
    for(auto & a:vec) showvec<T>(a,2);
    if(flag==1) cout<<endl;
}

// 一个错误的想法，这样的复杂度根本算不完，O(8^k)
class Solution_wrong {
public:
    double knightProbability(int n, int k, int row, int column) {
        if(row>n-1||row<0||column>n-1||column<0) return 0;
        if(k==0) return 1;
        double ans = 0;
        ans += knightProbability(n,k-1,row+2,column+1);
        ans += knightProbability(n,k-1,row+2,column-1);
        ans += knightProbability(n,k-1,row-2,column+1);
        ans += knightProbability(n,k-1,row-2,column-1);
        ans += knightProbability(n,k-1,row+1,column+2);
        ans += knightProbability(n,k-1,row+1,column-2);
        ans += knightProbability(n,k-1,row-1,column+2);
        ans += knightProbability(n,k-1,row-1,column-2);
        return ans/8;
    }
};

class Solution {
private :
    vector<vector<int>> dirs = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
    void update(vector<vector<double>> &list1,vector<vector<double>> &list2)
    {
        for(int i = 0;i<list1.size();i++) 
            for(int j = 0;j<list1.size();j++)
            {
                list2[i][j] = 0;
                for(auto & dir : dirs)
                {
                    int nx = dir[0] +i;
                    int ny = dir[1] +j;
                    if(nx>=0&&nx<list1.size()&&ny>=0&&ny<list1.size())
                    {
                        list2[i][j]+=list1[nx][ny]/8;
                    }
                }
            }
        showvec2<double>(list2);
    }
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> list = {vector<vector<double>>(n,vector<double>(n,1)),vector<vector<double>>(n,vector<double>(n,1))};
        int flag = 1;
        while(k)
        {
            k--;
            if(flag == 1) update(list[1],list[0]);
            else update(list[0],list[1]);
            flag = !flag; 
        }
        if(flag==1) return list[1][row][column];
        return list[0][row][column];
    }
};


int main()
{
    int n = 3;
    int k = 2;
    int row = 0;
    int column = 0;
    Solution slv;
    double ans = slv.knightProbability(n,k,row,column);
    cout<<ans;
    return 0;
}