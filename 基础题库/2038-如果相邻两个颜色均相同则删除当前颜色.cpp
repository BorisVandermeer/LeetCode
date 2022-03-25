#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<utility>
#include<map>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        int acnt = 0;
        int acnt2 = 0;
        int bcnt = 0;
        int bcnt2 = 0;
        for(auto & c:colors)
        {
            if(c=='A')
            {
                
                if(acnt2==2) acnt++;
                else{
                    bcnt2=0;
                    acnt2++;
                }
            }
            if(c=='B')
            {
                
                if(bcnt2==2) bcnt++;
                else{
                    acnt2=0;
                    bcnt2++;
                }
            }
        }
        if(acnt>bcnt) return true;
        return false;
    }
};

int main()
{
    Solution slv;

    auto ans = slv.winnerOfGame("AAABABB");
    cout<<ans;
    return 0;
}