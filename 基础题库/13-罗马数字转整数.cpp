#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        int i = 0;
        int cur=0;
        // 提取千位
        while(s[i]=='M')
        {
            cur+=1000;
            i++;
        }
        ans+=cur;
        cur=0;
        //提取百位
        if(s[i]=='C')
        {
            cur+=100;
            i++;
            if(s[i]=='M')
            {
                cur = 900;
                i++;
            }
            else if(s[i]=='D')
            {
                cur = 400;
                i++;
            }
            else while(s[i]=='C')
            {
                cur+=100;
                i++;
            }
        }
        else if(s[i]=='D')
        {
            cur+=500;
            i++;
            while(s[i]=='C')
            {
                cur+=100;
                i++;
            }
        }
        ans += cur;
        cur=0;
        //提取十位
        if(s[i]=='X')
        {
            cur+=10;
            i++;
            if(s[i]=='C')
            {
                cur = 90;
                i++;
            }
            else if(s[i]=='L')
            {
                cur = 40;
                i++;
            }
            else while(s[i]=='X')
            {
                cur+=10;
                i++;
            }
        }
        else if(s[i]=='L')
        {
            cur+=50;
            i++;
            while(s[i]=='X')
            {
                cur+=10;
                i++;
            }
        }
        ans+=cur;
        cur=0;
        //提取个位
        if(s[i]=='I')
        {
            cur+=1;
            i++;
            if(s[i]=='X')
            {
                cur = 9;
                i++;
            }
            else if(s[i]=='V')
            {
                cur=4;
                i++;
            }
            while(s[i]=='I')
            {
                cur+=1;
                i++;
            }
        }
        else if(s[i]=='V')
        {
            cur+=5;
            i++;
            while(s[i]=='I')
            {
                cur+=1;
                i++;
            }
        }
        ans+=cur;
        cur=0;
        return ans;
    }
};

int main()
{
    Solution slv;
    return slv.romanToInt("DCXXI");
}
