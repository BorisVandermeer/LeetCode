#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        int flag = 0;
        if(num==0) return "0";
        string tmp;
        if(num<0)
        {
            flag = 1;
            num=-num;
        }
        while(num)
        {
            tmp+='0'+num%7;
            num/=7;
        }
        string ans;
        if(flag) ans.push_back('-');
        for(int i=1;i<=tmp.length();i++)
        {
            ans.push_back(tmp[tmp.length()-i]);
        }
        return ans;
    }
};

int main()
{
    Solution slv;
    int num = 
    // 100;
    // -100;
    0;
    string ans = slv.convertToBase7(num);
    cout<<ans;
    return 0;
}