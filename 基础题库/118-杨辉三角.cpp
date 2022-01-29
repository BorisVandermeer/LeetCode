#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows==0) return ans;
        vector<int> base0 = {1};
        ans.push_back(base0);
        if(numRows==1) return ans;
        vector<int> base1 = {1,1};
        ans.push_back(base1);
        if(numRows==2) return ans;
        int flag = 0;
        for(int i = 3;i<=numRows;i++)
        {
            if(flag == 0) // 使用 base1中的值修改base0
            {
                flag = 1;
                base0.clear();
                base0.push_back(1);
                for(int j=1;j<i-1;j++)
                {
                    base0.push_back(base1[j-1]+base1[j]);
                }
                base0.push_back(1);
                ans.push_back(base0);
            }
            else// 使用 base0中的值修改base1
            {
                flag = 0;
                base1.clear();
                base1.push_back(1);
                for(int j=1;j<i-1;j++)
                {
                    base1.push_back(base0[j-1]+base0[j]);
                }
                base1.push_back(1);
                ans.push_back(base1);
            }
        }
        return ans;
    }
};

int main()
{
    Solution slv;
    vector<vector<int>> ans = slv.generate(10);
    for(auto vec : ans)
    {
        for(auto t : vec)
        {
            cout<<t<<", ";
        }
        cout<<endl;
    }
    return 1;
}