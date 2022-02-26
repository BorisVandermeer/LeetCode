#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

template<typename T=int>
void showvec(vector<T> vec,int D1Type=1,int D0Type = 3)
{
    if(D0Type = 2) for(auto & a:vec) cout<<a<<", ";
    else if(D0Type = 3) for(auto & a:vec) cout<<a<<' ';
    else for(auto & a:vec) cout<<a;
    if(D1Type==1) cout<<endl;
    if(D1Type==2) cout<<", ";
    if(D1Type==3) cout<<" ";
}

template<typename T=int>
void showvec2(vector<vector<T>> vec,int D2Type = 1,int D1Type=1)
{
    for(auto & a:vec) showvec<T>(a,D1Type);
    if(D2Type==1) cout<<endl;
}

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int pos4 = 0;
        int pos4max = nums.size()-4;
        long target_tmp = target-nums[0];
        int size = nums.size();
        int pos1max = size-3;
        int pos2max = size-2;
        int pos3max = size-1;
        while(pos4<=pos4max)
        {
            if(nums[pos4]>target/4) return ans;
            target_tmp = target-nums[pos4];
            int pos1 = pos4+1;
            int pos3 = size-1;
            int pos2 = pos4+2;
            while(pos1<=pos1max)
            {
                pos2 = pos1+1;
                pos3 = pos3max;
                while(pos2<pos3)
                {
                    int minustmp = target_tmp - nums[pos1] - nums[pos2] - nums[pos3];
                    cout<<pos4<<' '<<pos1<<' '<<pos2<<' '<<pos3<<' '<<minustmp<<endl;
                    if(minustmp==0)
                    {
                        ans.push_back({nums[pos4],nums[pos1],nums[pos2],nums[pos3]});
                        pos2++;
                        while(pos2<pos3&&nums[pos2]==nums[pos2-1]) pos2++;
                        pos3--;
                        while(pos3>pos2&&nums[pos3]==nums[pos3+1]) pos3--;
                    }
                    else if(minustmp>0)
                    {
                        pos2++;
                        while(pos2<pos3&&nums[pos2]==nums[pos2-1]) pos2++;
                    }
                    else if(minustmp<0)
                    {
                        pos3--;
                        while(pos3>pos2&&nums[pos3]==nums[pos3+1]) pos3--;
                    }
                }
                pos1++;
                while(pos1<=pos1max&&nums[pos1]==nums[pos1-1]) pos1++;
            }
            pos4++;
            while(pos4<=pos4max&&nums[pos4]==nums[pos4-1]) pos4++;
        }
        return ans;
    }
};

// 我也不知道为啥快这么多
class Solution_Key {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> quadruplets;
        if (nums.size() < 4) {
            return quadruplets;
        }
        sort(nums.begin(), nums.end());
        int length = nums.size();
        for (int i = 0; i < length - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if ((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            if ((long) nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target) {
                continue;
            }
            for (int j = i + 1; j < length - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                if ((long) nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target) {
                    continue;
                }
                int left = j + 1, right = length - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        left++;
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return quadruplets;
    }
};

int main()
{
    Solution slv;
    pair<int,vector<int>> Input = 
    // {0,{1,0,-1,0,-2,2}};
    // {0,{1000,1000,1000,1000}};
    {3032,{-499,-486,-479,-462,-456,-430,-415,-413,-399,-381,-353,-349,-342,-337,-336,-331,-330,-322,-315,-280,-271,-265,-249,-231,-226,-219,-216,-208,-206,-204,-188,-159,-144,-139,-123,-115,-99,-89,-80,-74,-61,-22,-22,-8,-5,4,43,65,82,86,95,101,103,123,149,152,162,165,168,183,204,209,209,220,235,243,243,244,248,253,260,273,281,284,288,290,346,378,382,384,407,411,423,432,433,445,470,476,497}};
    vector<int> & nums = Input.second;
    int target = Input.first;
    vector<vector<int>> ans = slv.fourSum(nums,target);
    cout<<endl;
    showvec2(ans);
    return 0;
}