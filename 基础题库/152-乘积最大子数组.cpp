#include<iostream>
#include<vector>

using namespace std;

#define Solution Solution_3

// 基础思路就是找到一段没有零的数组，如果负数的个数是基数个再定位到第一个位置和最后一个位置，再进行相乘
// 在Leetcode上面似乎会出现数组越界的问题 -> if(i==size||nums[i]==0) // 找到零了或者i越界了，要打断了
class Solution_1 {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if(size==1)
        {
            cout<<"Kidding me Only one val"<<endl;
            return nums[0];
        }
        int i = -1;
        int start_idx = 0;
        int cnt = 0;//当前位置负数的个数
        int max=INT32_MIN;
        int first_idx = 0;
        int last_idx = 0;
        while(1)
        {
            i++;
            if(nums[i]<0) //找到负数需要标记下来
            {
                if(!cnt) first_idx=i;
                last_idx=i;
                cnt++;
            }
            if(i==size||nums[i]==0) // 找到零了或者i越界了，要打断了
            {
                if(nums[i]==0) cout<<"In NUM == 0 Situation "<<endl;
                else cout<<"find the last vec"<<endl;
                cout<<"The last vec is :";
                for(int j=start_idx;j<i;j++) cout<<' '<<nums[j];
                cout<<endl;
                int max_2;
                if(start_idx==i)
                {
                    max_2 = 0;
                    cout<<"It's empty"<<endl;
                }
                else if(start_idx==i-1)
                {
                    max_2=std::max(nums[start_idx],0);
                    cout<<"Only one val"<<endl;
                }
                else if(cnt==1)
                {
                    int tmp1 = 1;int tmp2=1;
                    for(int j=start_idx;j<first_idx;j++)
                    {
                        tmp1*=nums[j];
                    }
                    for(int j=last_idx+1;j<i;j++)
                    {
                        tmp2*=nums[j];
                    }
                    max_2 = std::max(tmp1,tmp2);
                    cout<<"One val < 0"<<endl;
                }
                else if(cnt&1)
                {
                    int tmp1=1;int tmp2=1;int tmp3=1;
                    for(int j=start_idx;j<=first_idx;j++)
                    {
                        tmp1*=nums[j];
                    }
                    for(int j=last_idx;j<i;j++)
                    {
                        tmp3*=nums[j];
                    }
                    for(int j=first_idx+1;j<last_idx;j++)
                    {
                        tmp2*=nums[j];
                    }
                    max_2 = tmp2*min(tmp1,tmp3);
                    cout<<"old num of val<0 in here"<<endl;
                }
                else
                {
                    max_2=1;
                    for(int j=start_idx;j<i;j++)
                    {
                        max_2*=nums[j];
                    }
                    cout<<"even num of val<0 in here"<<endl;
                }
                
                cout<<"The max we think is : "<<std::max(max,max_2)<<"  Form "<<max<<" and "<<max_2<<endl<<endl;
                max = std::max(max,max_2);
                start_idx = i+1;
                cnt = 0;
            }
            if(i==size) break;
        }
        return max;
    }
};
// 解决数组越界的问题
class Solution_2 {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if(nums.size()==1)
        {
            cout<<"Kidding me Only one val"<<endl;
            return nums[0];
        }
        nums.push_back(0);
        int i = -1;
        int start_idx = 0;
        int cnt = 0;//当前位置负数的个数
        int max=INT32_MIN;
        int first_idx = 0;
        int last_idx = 0;
        while(1)
        {
            i++;
            if(nums[i]<0) //找到负数需要标记下来
            {
                if(!cnt) first_idx=i;
                last_idx=i;
                cnt++;
            }
            if(nums[i]==0) // 找到零了或者i越界了，要打断了
            {
                if(nums[i]==0) cout<<"In NUM == 0 Situation "<<endl;
                else cout<<"find the last vec"<<endl;
                cout<<"The last vec is :";
                for(int j=start_idx;j<i;j++) cout<<' '<<nums[j];
                cout<<endl;
                int max_2;
                if(start_idx==i)
                {
                    max_2 = 0;
                    cout<<"It's empty"<<endl;
                }
                else if(start_idx==i-1)
                {
                    max_2=std::max(nums[start_idx],0);
                    cout<<"Only one val"<<endl;
                }
                else if(cnt==1)
                {
                    int tmp1 = 1;int tmp2=1;
                    for(int j=start_idx;j<first_idx;j++)
                    {
                        tmp1*=nums[j];
                    }
                    for(int j=last_idx+1;j<i;j++)
                    {
                        tmp2*=nums[j];
                    }
                    max_2 = std::max(tmp1,tmp2);
                    cout<<"One val < 0"<<endl;
                }
                else if(cnt&1)
                {
                    int tmp1=1;int tmp2=1;int tmp3=1;
                    for(int j=start_idx;j<=first_idx;j++)
                    {
                        tmp1*=nums[j];
                    }
                    for(int j=last_idx;j<i;j++)
                    {
                        tmp3*=nums[j];
                    }
                    for(int j=first_idx+1;j<last_idx;j++)
                    {
                        tmp2*=nums[j];
                    }
                    max_2 = tmp2*min(tmp1,tmp3);
                    cout<<"old num of val<0 in here"<<endl;
                    cout<<"And tmps is : "<<tmp1<<' '<<tmp2<<' '<<tmp3<<endl;
                }
                else
                {
                    max_2=1;
                    for(int j=start_idx;j<i;j++)
                    {
                        max_2*=nums[j];
                    }
                    cout<<"even num of val<0 in here"<<endl;
                }
                
                cout<<"The max we think is : "<<std::max(max,max_2)<<"  Form "<<max<<" and "<<max_2<<endl<<endl;
                max = std::max(max,max_2);
                cnt = 0;
                start_idx = i+1;
            }
            if(i==size) break;
        }
        return max;
    }
};

class Solution_2_WithoutCouts {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if(nums.size()==1) return nums[0];
        nums.push_back(0);
        int i = -1;
        int start_idx = 0;
        int cnt = 0;//当前位置负数的个数
        int max=INT32_MIN;
        int first_idx = 0;
        int last_idx = 0;
        while(1)
        {
            i++;
            if(nums[i]<0) //找到负数需要标记下来
            {
                if(!cnt) first_idx=i;
                last_idx=i;
                cnt++;
            }
            if(nums[i]==0) // 找到零了或者i越界了，要打断了
            {
                int max_2;
                if(start_idx==i) max_2 = 0;
                else if(start_idx==i-1) max_2=std::max(nums[start_idx],0);
                else if(cnt==1)
                {
                    int tmp1 = 1;int tmp2=1;
                    for(int j=start_idx;j<first_idx;j++)
                    {
                        tmp1*=nums[j];
                    }
                    for(int j=last_idx+1;j<i;j++)
                    {
                        tmp2*=nums[j];
                    }
                    max_2 = std::max(tmp1,tmp2);
                }
                else if(cnt&1)
                {
                    int tmp1=1;int tmp2=1;int tmp3=1;
                    for(int j=start_idx;j<=first_idx;j++)
                    {
                        tmp1*=nums[j];
                    }
                    for(int j=last_idx;j<i;j++)
                    {
                        tmp3*=nums[j];
                    }
                    for(int j=first_idx+1;j<last_idx;j++)
                    {
                        tmp2*=nums[j];
                    }
                    max_2 = tmp2*min(tmp1,tmp3);
                }
                else
                {
                    max_2=1;
                    for(int j=start_idx;j<i;j++)
                    {
                        max_2*=nums[j];
                    }
                }
                max = std::max(max,max_2);
                cnt = 0;
                start_idx = i+1;
            }
            if(i==size) break;
        }
        return max;
    }
};

// 放弃通过逻辑减少乘法次数了
class Solution_3 {
public:
    int maxProduct(vector<int>& nums) {
        int maxF = nums[0], minF = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int mx = maxF, mn = minF;
            maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
            minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
            ans = max(maxF, ans);
        }
        return ans;
    }
};

// 一个思路类似的答案,但比我好太多了
class Solution_answers1 {
public:
    int maxProduct(vector<int> & nums) {
        int a=1;  
        int max=nums[0];
        
        for(int num:nums){
            a=a*num;
            if(max<a)max=a;
            if(num==0)a=1;

        }
        a=1;
        for(int i=nums.size()-1;i>=0;i--){
            a=a*nums[i];
            if(max<a)max=a;
            if(nums[i]==0)a=1;
        }  
        return max;
    }
};

int main()
{
    Solution slv;
    vector<int> nums=
    // {2,3,-2,4};
    // {-3,0,1,-2};
    // {-2,0,-1};
    //{1,2,3,0,-9,-8,-7,-6,0,0,8,0};
    {2,-5,-2,-4,3};
    int ans = slv.maxProduct(nums);
    return ans;
}