#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<utility>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<memory>

using namespace std;

class Solution {
public:
    bool reachingPoints(int sx, int sy, int  tx, int  ty) {
        while(1)
        {
            
            if(tx==sx && ty ==sy) return true; 
            if(tx==ty) return false;
            if(tx>ty)
            {
                if(sx>=ty) tx -= (tx - sx)>ty?(tx - sx)/ty *ty:ty;
                else if(tx>=ty) tx -= (tx - ty)/ty * ty + ty;
                if(tx<sx) return false;
            }
            else if(tx<ty)
            {
                if(sy>=tx) ty -= (ty - sy)>tx ? (ty - sy)/tx * tx : tx;
                else if(tx<=ty) ty -= (ty - tx)/tx * tx + tx;
                if(ty<sy) return false;
            }
            
        }
        return false;
    }
};

int main()
{
    Solution slv;
    auto ans = slv.reachingPoints
    // (1,1,3,2);
    // (1,7,999999995,7);
    // (1,8,999999993,8);
    (10,5,15,5);
    cout<<ans;
    return 0;
}

