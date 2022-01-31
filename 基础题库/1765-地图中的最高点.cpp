#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

void Showvecvecint(vector<vector<int>>& vec)
{
    for(auto & row:vec)
    {
        for(auto & val : row)
        {
            cout<<" "<<val;
        }
        cout<<endl;
    }
}

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int H = isWater.size();
        int W = isWater[0].size();
        int cnt = 1;
        int cur = -1;
        int flag=0; // Last Data SavePlace
        vector<vector<int>> DataSpace1;
        vector<vector<int>> DataSpace0;
        vector<vector<int>> ans(H,vector<int>(W,-1));
        for(int i=0;i<H;i++) for(int j=0;j<W;j++) if(isWater[i][j]) DataSpace0.push_back({i,j});
        while(cnt)
        {
            cnt = 0;
            cur++;
            if(flag==0) 
            {
                for(auto & Point:DataSpace0)
                {
                    if(Point[0]>-1&&Point[1]>-1&&Point[0]<H&&Point[1]<W&&ans[Point[0]][Point[1]]==-1)
                    {
                        ans[Point[0]][Point[1]] = cur;
                        DataSpace1.push_back({Point[0],Point[1]-1}); //TOP
                        DataSpace1.push_back({Point[0],Point[1]+1}); //BOT
                        DataSpace1.push_back({Point[0]-1,Point[1]}); //LEFT
                        DataSpace1.push_back({Point[0]+1,Point[1]}); //RIGHT
                        cnt++;
                    }
                }
                flag = 1;
                DataSpace0.clear();
                //Showvecvecint(DataSpace1);
            }
            else
            {
                for(auto & Point:DataSpace1)
                {
                    if(Point[0]>-1&&Point[1]>-1&&Point[0]<H&&Point[1]<W&&ans[Point[0]][Point[1]]==-1)
                    {
                        ans[Point[0]][Point[1]] = cur;
                        DataSpace0.push_back({Point[0],Point[1]-1}); //TOP
                        DataSpace0.push_back({Point[0],Point[1]+1}); //BOT
                        DataSpace0.push_back({Point[0]-1,Point[1]}); //LEFT
                        DataSpace0.push_back({Point[0]+1,Point[1]}); //RIGHT
                        cnt++;
                    }
                }
                flag = 0;
                DataSpace1.clear();
                //Showvecvecint(DataSpace0);
            }
        }
        return ans;
    }
};

int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution_LeetcodeKey{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1)); // -1 表示该格子尚未被访问过
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j]) {
                    ans[i][j] = 0;
                    q.emplace(i, j); // 将所有水域入队
                }
            }
        }
        while (!q.empty()) {
            auto &p = q.front();
            for (auto &dir : dirs) {
                int x = p.first + dir[0], y = p.second + dir[1];
                if (0 <= x && x < m && 0 <= y && y < n && ans[x][y] == -1) {
                    ans[x][y] = ans[p.first][p.second] + 1;
                    q.emplace(x, y);
                }
            }
            q.pop();
        }
        return ans;
    }
};



int main()
{
    vector<vector<int>> vec = 
    // {
    //     {0,1,1,1},
    //     {1,1,1,1}
    // };
    // {
    //     {0,0,1},
    //     {1,0,0},
    //     {0,0,0}
    // };
    {
        {1}
    };
    Solution slv;
    vec = slv.highestPeak(vec);
    for(auto & row:vec)
    {
        for(auto & val : row)
        {
            cout<<" "<<val;
        }
        cout<<endl;
    }
    return 1;
}


