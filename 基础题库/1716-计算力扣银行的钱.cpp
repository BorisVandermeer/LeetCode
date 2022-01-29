#include<iostream>
using namespace std;
class Solution {
public:
    int totalMoney(int n) {
        int weeks = n/7;
        int days = n%7;
        int ans = (49+7*weeks)*weeks/2+weeks*days+(days*days+days)/2;
        return ans;
    }
};

class Solution2 {
public:
    int totalMoney(int n) {
        int weeks = (n/7);
        int days = (n%7);
        return ((49+7*weeks)*weeks/2+weeks*days+(days*days+days)/2);
    }
};

class Solution2 {
public:
    int totalMoney(int n) {
        return ((49+7*(n/7))*(n/7)/2+(n/7)*(n%7)+((n%7)*(n%7)+(n%7))/2);
    }
};

class Solution3 {
public:
    int totalMoney(int n) {
        return (49+7*(n / 7))*(n / 7)/2+(2*(n / 7)+1+(n % 7))*(n % 7)/2;
    }
};

int main()
{   
    Solution slv;
    auto ans = slv.totalMoney(2);
    cout<<ans<<endl; //String || int 
    return 1;
}