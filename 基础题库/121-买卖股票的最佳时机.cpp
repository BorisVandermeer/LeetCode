#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int min = prices[0];
        int max = prices[0];
        for(auto & price:prices)
        {
            if(price<min)
            {
                if(max-min>ans) ans=max-min;
                min=price;
                max = min;
            }
            else
            {
                if(max<price) max=price;
            }
        }
         if(max-min>ans) ans=max-min;
         return ans;

    }
};

int main()
{
    Solution slv;
    vector<int> prices = 
    // {7,1,5,3,6,4};
    {7,6,4,3,1};
    int ans = slv.maxProfit(prices);
    cout<<ans;
    return 0;
}