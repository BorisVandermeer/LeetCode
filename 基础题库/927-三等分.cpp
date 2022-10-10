#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<utility>
#include<stack>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<string.h>


using namespace std;

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        // 确定1的个数
        vector<int> ans = {0,0};
        int counter = 0;
        for(auto & bit : arr)
        {
            if(bit) counter++;
        }
        if(counter == 0)  return {0,2};
        if(counter%3 !=0) return {-1,-1};
        counter /= 3;
        int tailzeros = arr.size()-1; // 初始化用
        while(arr[tailzeros] == 0) tailzeros--;
        tailzeros = arr.size()-1-tailzeros;
        int & ansi = ans[0];
        int & ansj = ans[1];
        int h1 = 0;
        while(arr[h1]==0) h1++;
        int tmpcnt = 0;
        while(tmpcnt<counter) if(arr[ansi++]) tmpcnt++;   
        ansi+=tailzeros-1;
        int h2(ansi+1);
        while(!arr[h2]) h2++;
        ansj = h2+ansi-h1+1; // 后半部分是这个数字的长度
        int h3(ansj);
        while(!arr[h3]) h3++;
        while(h1<=ansi)
        {
            if(arr[h1]!=arr[h2]||arr[h2]!= arr[h3]) return {-1,-1};
            h1++;h2++;h3++;
        }
        return ans;
    }
};

class Solution_MemoryBetter {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        // 确定1的个数
        vector<int> ans = {0,0};
        int h1 = 0;
        int h2 = 0;
        int h3 = arr.size()-1; // 初始化用
        for(auto & bit : arr) if(bit) h2++;
        if(h2 == 0)  return {0,2};
        if(h2%3 !=0) return {-1,-1};
        h2 /= 3;
        while(arr[h3] == 0) h3--;
        h3 = arr.size()-1-h3;
        int & ansi = ans[0];
        int & ansj = ans[1];

        while(arr[h1]==0) h1++;
        int tmpcnt = 0;
        while(tmpcnt<h2) if(arr[ansi++]) tmpcnt++;   
        ansi+=h3-1;
        h2= ansi+1;
        while(!arr[h2]) h2++;
        ansj = h2+ansi-h1+1; // 后半部分是这个数字的长度
        h3 = ansj;
        while(!arr[h3]) h3++;
        while(h1<=ansi)
        {
            if(arr[h1]!=arr[h2]||arr[h2]!= arr[h3]) return {-1,-1};
            h1++;h2++;h3++;
        }
        return ans;
    }
};



int main()
{
    Solution slv;

    vector<int> arr=
    {1,0,1,0,1};

    auto ans = slv.threeEqualParts(arr);
    // cout<<ans;
    return 0;
}