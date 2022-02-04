#include<iostream>
#include<vector>

using namespace std;

//每跳一次都记录下能跳到的最远距离，然后再判断而者之间，不停的
class Solution {
public:
    int jump(vector<int>& nums) {
        int Times = 0;
        int Jump_Max = 0;
        int Jump_Last = -1;
        int Target = nums.size()-1;
        while(Jump_Max<Target)
        {
            Times++;
            int Tmp_Jump_Max=0;
            for(int i = Jump_Last+1;i<=Jump_Max;i++)
            {
                if(i+nums[i]>Tmp_Jump_Max) Tmp_Jump_Max=i+nums[i];
                if(Tmp_Jump_Max>Target) return Times; //这一句话快了一半，快速跳出
            }
            Jump_Last = Jump_Max;
            Jump_Max = Tmp_Jump_Max;
        }
        return Times;
    }
};

int main()
{
    Solution slv;
    vector<int> nums = {2,3,1,1,4};
    return slv.jump(nums);
}