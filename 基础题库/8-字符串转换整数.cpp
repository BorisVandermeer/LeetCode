#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int flag = 1;
        int firstdata_idx=0;
        for(auto c : s)
        {
            if(c!=' ') break;
            firstdata_idx++;
        }
        if(s[firstdata_idx]=='+') firstdata_idx++;
        else if(s[firstdata_idx]=='-')
        {
            firstdata_idx++;
            cout<<"flag"<<endl;
            flag = -1;
        }
        for(int i=firstdata_idx;i<s.length();i++)
        {
            if(s[i] == 0) firstdata_idx++;
            else break;
        }
        int line = INT32_MAX/10;
        int val = 0;
        for(int i=firstdata_idx;i<s.length();i++)
        {
            int cur_val = (int)s[i]-(int)'0';
            if(cur_val<0||cur_val>9) break;
            if(val>line)
            {
                if(flag==-1) return INT32_MIN;
                return INT32_MAX;
            }
            val = val * 10;
            if(flag==1&&val>line&&cur_val>INT32_MAX-val) return INT32_MAX;
            if(flag==-1&&val>line&&cur_val-1>INT32_MAX-val) return INT32_MIN;
            val = val+cur_val;
        }
        
        if(flag == 1) return val;
        return -val;
    }
};

int main()
{
    Solution slv;
    int ans = slv.myAtoi("-2147483648");
    return -ans;
}