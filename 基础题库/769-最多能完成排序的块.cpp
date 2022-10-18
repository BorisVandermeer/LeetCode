#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<utility>
#include<stack>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<set>
#include<unordered_set>
#include<string.h>


using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cur_head = 0;
        int cur_tail = 0;
        int ans = 0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>cur_tail) cur_tail = arr[i];
            if(cur_tail== i)
            {
                ans++;
                cur_head = cur_tail+1;
                cur_tail++;
            }
        }
        return ans;

    }
};

class Solution_better {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cur_tail = 0;
        int ans = 0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>cur_tail) cur_tail = arr[i];
            if(cur_tail== i) ans++;
        }
        return ans;

    }
};

int main()
{
    Solution slv;
    vector<int> arr = {1,0,2,3,4};

    auto ans = slv.maxChunksToSorted(arr);
    cout<<ans;
    return 0;
}