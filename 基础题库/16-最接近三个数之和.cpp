#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

//双指针移动，不停地计算距离，如果和大于等于
class Solution {
    // inline int distance(int a,int b)
    // {
    //     return a>b?a-b:b-a;
    // }
public:
    int threeSumClosest(vector<int>& nums, int target){
        sort(nums.begin(),nums.end());
        int size = nums.size();
        int mindis = INT32_MAX;
        int ans = INT32_MIN;
        int pos1 = 0;
        int pos3 = size-1;
        int pos2 = 1;
        int pos1max = size-3;
        int pos2max = size-2;
        int pos3max = size-1;
        //cout<<"Start Threesum"<<endl;
        while(pos1<=pos1max)
        {
            pos2 = pos1+1;
            pos3 = pos3max;
            while(pos2<pos3)
            {
                
                int minustmp = target - nums[pos1] - nums[pos2] - nums[pos3];
                cout<<pos1<<' '<<pos2<<' '<<pos3<<' '<<minustmp <<endl;
                if(minustmp>mindis)
                {
                    pos2++;
                    while(pos2<pos3&&nums[pos2]==nums[pos2-1]) pos2++;
                }
                else if(minustmp<-mindis)
                {
                    pos3--;
                    while(pos3>pos2&&nums[pos3]==nums[pos3+1]) pos3--;
                }
                else
                {
                    if(minustmp==0) return target;
                    if(minustmp<0)
                    {
                        mindis = -minustmp;
                        ans = target+mindis;
                        pos3--;
                        while(pos2<pos3&&nums[pos3]==nums[pos3+1]) pos3--;
                    }
                    else
                    {
                        mindis = minustmp;
                        ans = target-mindis;
                        pos2++;
                        while(pos2<pos3&&nums[pos2]==nums[pos2-1]) pos2++;
                    }
                }
            }
            pos1++;
            while(pos1<=pos1max&&nums[pos1]==nums[pos1-1]) pos1++;
        }
        return ans;
    }
};

int main()
{
    Solution slv;
    pair<int,vector<int>> input
    // (1,{-1,2,1,-4});
    // (3,{0,0,0});
    // {100,{1,1,1,0}};
    (82,{1,2,3,8,16,32,64,128});
    vector<int> & nums = input.second;
    int & target = input.first;
    int ans = slv.threeSumClosest(nums,target);
    cout<<ans;
    return 0;
}