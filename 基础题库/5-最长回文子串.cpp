#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int lenmax_idx = 0;
        int max_len = 0;
        for(int i=0;i<s.length();i++)
        {
            //长度为偶数的
            {
                int j=0;
                int lencnt = 0;
                while(j<=i&&j+i+1<s.length())
                {
                    if(s[i-j]!=s[i+j+1]) break;
                    lencnt += 2;
                    j++;
                }
                if(lencnt>max_len)
                {
                    lenmax_idx = i;
                    max_len = lencnt;
                }
            }
            //长度为奇数的
            {
                int j=1;
                int lencnt = 1;
                while(j<=i&&j+i<s.length())
                {
                    if(s[i-j]!=s[i+j]) break;
                    lencnt += 2;
                    j++;
                }
                if(lencnt>max_len)
                {
                    lenmax_idx = i;
                    max_len = lencnt;
                }
            }
        }
        string ans;
        cout<<"max length is "<<max_len<<endl;
        if(max_len%2==1) ans.insert(ans.back(),s,lenmax_idx-max_len/2,max_len);
        if(max_len%2==0) ans.insert(ans.back(),s,lenmax_idx-max_len/2+1,max_len);
        return ans;
    }
};

int main()
{   
    Solution slv;
    string str("cccc");
    auto ans = slv.longestPalindrome(str);
    cout<<ans<<endl;
    return 1;
}
