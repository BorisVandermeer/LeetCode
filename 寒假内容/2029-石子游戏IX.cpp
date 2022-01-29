#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int val:stones)
        {
            int num = val%3;
            switch (num)
            {
            case 0: cnt0++;break;
            case 1: cnt1++;break;
            case 2: cnt2++;break;
            default:break;
            }
        }
        if(cnt1+cnt2<=1) return false;
        if((cnt1==0||cnt2==0)&&(cnt1+cnt2==2)) return false;
        if(cnt2-cnt1>=-2&&cnt2-cnt1<=2)
        {
            if(cnt0%2==0) return true;
            return false;
        }
        if(cnt1==0||cnt2==0)
        {
            if(cnt0%2==0) return false;
            return true;
        }
        return true;
    }
}; 

int main()
{
    Solution slv;
    vector<int> vec= {2,1};
    return slv.stoneGameIX(vec);
}