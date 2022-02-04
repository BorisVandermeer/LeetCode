#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int len = 0;
        int cnt = 0;
        for(auto & rec:rectangles)
        {
            int len_tmp = min(rec[1],rec[0]);
            if(len_tmp==len)
            {
                cnt++;
                continue;
            }
            if(len_tmp>len)
            {
                len = len_tmp;
                cnt = 1;
                continue;
            }
        }
        return cnt;
    }
};

int main()
{
    Solution slv;
    vector<vector<int>> rectangles = 
    {
        {2,3},{3,7},{4,3},{3,7},{5,6}
    };
    return slv.countGoodRectangles(rectangles);
}
