#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

class Solution {

public:
    string complexNumberMultiply(string num1, string num2) {
        stringstream ss1(num1);
        stringstream ss2(num2);
        int a,b,c,d;
        char t;
        ss1>>a>>t>>c;
        ss2>>b>>t>>d;
        return to_string(a*b-c*d)+'+'+to_string(a*d+b*c)+'i';
    }
};

int main()
{
    Solution slv;
    vector<string> nums_in = 
    // {"1+1i","1+1i"};
    {"1+-1i","0+0i"};
    string & num1 = nums_in[1];
    string & num2 = nums_in[1];
    string ans = slv.complexNumberMultiply(num1,num2);
    cout<<ans;
    return 0;
}

