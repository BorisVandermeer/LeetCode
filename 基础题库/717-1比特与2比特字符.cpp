#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i=0;
        while(1)
        {
            if(bits[i]==1) 
            {
                i++;
                if(i==bits.size()-1) return false;
            }
            i++;
            if(i==bits.size()-1) return true;
        }
    }
};

int main()
{
    Solution slv;
    vector<int> bits =
    {1,1,1,1,0};
    bool ans = slv.isOneBitCharacter(bits);
    cout<<ans;
    return 0;
}