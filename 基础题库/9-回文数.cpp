#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> t;
        if(x<0) return false;
        while(x)
        {
            t.push_back(x%10);
            x /= 10;
            cout<<x<<endl;
        }
        for(int i=0;i<t.size()/2;i++)
        {
            if(t[i]!=t[t.size()-i-1]) return false;
        }
        return true;
    }
};

class Solution2 { // 此时可能会因为反转超出 int
public:
    bool isPalindrome(int x) {
        int rev=0;
        int y = x;
        if(!x) return true;
        if(x<0||x%10==0) return false;
        while(x)
        {
            rev = rev*10 + x%10;
            x /= 10;
        }
        if(rev==y)return true;
        return false;
    }
};

class Solution3 {
public:
    bool isPalindrome(int x) {
        int rev=0;
        int y = x;
        if(!x) return true;
        if(x<0||x%10==0) return false;
        while(x>rev)
        {
            rev = rev*10 + x%10;
            x /= 10;
        }
        return x == rev || x == rev / 10;
    }
};

int main()
{
    Solution2 slv;
    int x = 121212;
    return slv.isPalindrome(x);
}