#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        string data[numRows];
        int cur_row = 0;
        int flag_dwn = 1;
        int cnt_er = 0;
        if(numRows == 1) return s;
        for(char c : s)
        {
            if(cur_row==0)
            {
                flag_dwn=1;
                data[0].push_back(c);
                cur_row++;
            }
            else if(cur_row==numRows-1)
            {
                flag_dwn=0;
                data[numRows-1].push_back(c);
                cur_row--;
            }
            else if(flag_dwn==0)
            {
                data[cur_row].push_back(c);
                cur_row--;
            }
            else if(flag_dwn==1)
            {
                data[cur_row].push_back(c);
                cur_row++;
            }
        }
        string ans;
        for(int i=0;i<numRows;i++)
        {
            ans += data[i];
        }
        return ans;
    }
};

int main()
{   
    Solution slv;
    string str("cccccccccc");
    auto ans = slv.convert(str,3);
    cout<<ans<<endl;
    return 1;
}