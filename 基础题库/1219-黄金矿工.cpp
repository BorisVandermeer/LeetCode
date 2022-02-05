#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    int size_x;
    int size_y;
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        //vector<vector<int>> CurMapGone;
        size_x = grid.size();
        size_y = grid[0].size();
        int max_gold = 0;
        for(int i = 0;i<size_x;i++) 
        {
            for(int j = 0;j<size_y;j++)
            {
                if(grid[i][j]!=0)
                {
                    int tmp = SearchForMaxGold(i,j,grid);
                    if(tmp>max_gold)
                    {
                        max_gold = tmp;
                    }
                }
            }
        }
        return max_gold;
    }

    int SearchForMaxGold(int x,int y,vector<vector<int>>& grid)
    {
        int max_gold=0;
        int tmp_backup = grid[x][y];
        if(tmp_backup==0) return 0;
        grid[x][y] = 0;
        if(x>0)
        {
            max_gold = SearchForMaxGold(x-1,y,grid);
        }
        if(y>0)
        {
            int tmp = SearchForMaxGold(x,y-1,grid);
            if(tmp>max_gold) max_gold = tmp;
        }
        if(x<size_x-1)
        {
            int tmp = SearchForMaxGold(x+1,y,grid);
            if(tmp>max_gold) max_gold = tmp;
        }
        if(y<size_y-1)
        {
            int tmp = SearchForMaxGold(x,y+1,grid);
            if(tmp>max_gold) max_gold = tmp;
        }
        grid[x][y] = tmp_backup;
        return max_gold+tmp_backup;
    }
};

int main()
{
    Solution slv;
    vector<vector<int>> grid=
    {
        {0,6,0},
        {5,8,7},
        {0,9,0}
    };
    auto ans = slv.getMaximumGold(grid);
    cout<<endl<<"ANS : "<< ans;
    return 0;
}