#include<iostream>
#include<vector>
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

// 不断将最大值反转到最后一个元素上
class Solution {
private:
    void reverse(vector<int>& arr,int n)
    {
        int left=0,right=n;
        int temp=0;
        while(left<right)
        {
            temp=arr[left];
            arr[left]=arr[right];
            arr[right]=temp;
            left++;
            right--;
        }
    }

    int Idx0fMaxElement(vector<int>& arr,int n)
    {
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            if(arr[i]>arr[ans])
            {
                ans = i;
            }
        }
        return ans;
    }
public:
    vector<int> pancakeSort(vector<int>& arr)
    {
        vector<int> ans;
        for(int i = arr.size()-1;i>0;i--)
        {
            int idx = Idx0fMaxElement(arr,i);
            if(idx==i) continue;
            reverse(arr,idx);
            ans.push_back(idx+1);
            reverse(arr,i);
            ans.push_back(i+1);
        }
        return ans;
    }
};

int main()
{
    Solution slv;
    vector<int> arr = 
    // {3,2,4,1};
    {1,2,3,4};
    vector<int> tar(arr);
    vector<int> ans = slv.pancakeSort(arr);
    showvec(ans);
    showvec(arr);
    return 0;
}