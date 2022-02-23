#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> bit;
        string ans;   
label1:
        bit.push_back(num%10);
        num/=10;
        if(num>0) goto label1;
        if(bit.size()==4)
        {
            int & p = bit.back();
            bit.pop_back();
            if(p==3) ans+="MMM";
            else if(p==2) ans+="MM";
            else if(p==1) ans+="M";
        }
        if(bit.size()==3)
        {
            int & p = bit.back();
            bit.pop_back();
            if(p==9) ans+="CM";
            else
            {
                if(p>5)
                {
                    ans+="D";
                    p-=5;
                }
                if(p==4) ans+="CD";
                else if(p==3) ans+="CCC";
                else if(p==2) ans+="CC";
                else if(p==1) ans+="C";
            }
        }
        if(bit.size()==2)
        {
            int & p = bit.back();
            bit.pop_back();
            if(p==9) ans+="XC";
            else
            {
                if(p>5)
                {
                    ans+="L";
                    p-=5;
                }
                if(p==4) ans+="XL";
                else if(p==3) ans+="XXX";
                else if(p==2) ans+="XX";
                else if(p==1) ans+="X";
            }
        }
        if(bit.size()==1)
        {
            int & p = bit.back();
            bit.pop_back();
            if(p==9) ans+="IX";
            else
            {
                if(p>5)
                {
                    ans+="V";
                    p-=5;
                }
                if(p==4) ans+="IV";
                else if(p==3) ans+="III";
                else if(p==2) ans+="II";
                else if(p==1) ans+="I";
            }
        }
        return ans;
    }
};

int main()
{
    Solution slv;
    int num = 
    // 3;
    123;
    cout<<"Test Begin"<<endl;
    string ans = slv.intToRoman(num);
    cout<<ans;
    return 0;
}