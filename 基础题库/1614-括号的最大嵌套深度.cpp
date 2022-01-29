#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int maxdepth = 0;
        for(char c:s)
        {
            if(c=='(')
            {
                count++;
            }
            if(c==')')
            {
                if(maxdepth<count) maxdepth = count;
                count--;
            }
        }
        return maxdepth;
    }
};

int main()
{   
    Solution slv;
    string c("1+(2*3)/(2-1)");
    return slv.maxDepth(c);
}