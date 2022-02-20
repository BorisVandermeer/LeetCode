#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int size = haystack.length()-needle.length();
        for(int i=0;i<=size;i++)
        {
            bool flag=true;
            for(int j=0;j<needle.length();j++)
            {
                if(haystack[i+j]!=needle[j])
                {
                    flag = false;
                }
            }
            if(flag) return i;
        }
        return -1;
    }
};

int main()
{
    Solution slv;
    string haystack = "needllllasdgas";
    string needle = "nd";
    int ans = slv.strStr(haystack,needle);
    cout<<ans;
    return 0;
}