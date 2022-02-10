#include<iostream>
#include<vector>

using namespace std;

class Solution {
public :
    bool judge2Point(int a,int b,int target = 24)
    {
        if(a+b==target) return true;
        if(a*b==target) return true;
        if(a<b) fooo(a,b);
        if(a-b==target) return true;
        if(b!=0) if(a%b==0) if(a/b==target) return true;
        return false;
    }

    bool judge3Point(int a,int b,int c,int target = 24)
    {
        if(a<b) fooo(a,b);if(a<c) fooo(a,c);
        if(b<c) fooo(b,c);
        if(c==0) return (a==24||b==24||judge2Point(a,b,24));
        if(judge2Point(a+b,c,target)) return true;
        if(judge2Point(a+c,b,target)) return true;
        if(judge2Point(c+b,a,target)) return true;
        
        if(judge2Point(a-b,c,target)) return true;
        if(judge2Point(a-c,b,target)) return true;
        if(judge2Point(b-a,c,target)) return true;
        if(judge2Point(b-c,a,target)) return true;
        if(judge2Point(c-b,a,target)) return true;
        if(judge2Point(c-a,b,target)) return true;
        
        if(judge2Point(a*b,c,target)) return true;
        if(judge2Point(b*c,a,target)) return true;
        if(judge2Point(a*c,b,target)) return true;
        
        if(a%b==0) if(judge2Point(a/b,c,target)) return true;
        if(b%a==0) if(judge2Point(b/a,c,target)) return true;
        if(a%c==0) if(judge2Point(a/c,b,target)) return true;
        if(c%a==0) if(judge2Point(c/a,b,target)) return true;
        if(b%c==0) if(judge2Point(b/c,a,target)) return true;
        if(c%b==0) if(judge2Point(c/b,a,target)) return true;
        return false;
    }
public:
    bool judgePoint24(vector<int>& cards) {
        int & a=cards[0];int & b=cards[1];int & c=cards[2];int & d=  cards[3];
        if(a<b) fooo(a,b); if(a<c) fooo(a,c);if(a<d) fooo(a,d);
        if(b<c) fooo(b,c); if(b<d) fooo(b,d);
        if(c<d) fooo(c,d);      

        if(judge3Point(a+b,c,d)) return true;
        if(judge3Point(a+c,b,d)) return true;
        if(judge3Point(a+d,b,c)) return true;
        if(judge3Point(b+c,a,d)) return true;
        if(judge3Point(b+d,a,c)) return true;
        if(judge3Point(c+d,a,b)) return true;
        
        if(judge3Point(a*b,c,d)) return true;
        if(judge3Point(a*c,b,d)) return true;
        if(judge3Point(a*d,b,c)) return true;
        if(judge3Point(b*c,a,d)) return true;
        if(judge3Point(b*d,a,c)) return true;
        if(judge3Point(c*d,a,b)) return true;

        if(judge3Point(a-b,c,d)) return true;
        if(judge3Point(a-c,b,d)) return true;
        if(judge3Point(a-d,b,c)) return true;
        if(judge3Point(b-c,a,d)) return true;
        if(judge3Point(b-d,a,c)) return true;
        if(judge3Point(c-d,a,b)) return true;

        if(a%b==0) if(judge3Point(a/b,c,d)) return true;
        if(a%c==0) if(judge3Point(a/c,b,d)) return true;
        if(a%d==0) if(judge3Point(a/d,b,c)) return true;
        if(b%c==0) if(judge3Point(b/c,a,d)) return true;
        if(b%d==0) if(judge3Point(b/d,a,c)) return true;
        if(c%d==0) if(judge3Point(c/d,a,b)) return true;

        if(c==b) if((a+d)%b==0) if((a+d)/b==24) return true;
        if(c==d) if((a+b)%c==0) if((a+b)/c==24) return true;
        if(a==b) if(judge2(c,d,a)) return true;
        if(b==c) if(judge2(a,d,c)) return true;
        if(c==d) if(judge2(a,b,c)) return true;
        if(judge(a*c,b*c,d)) return true;
        if(judge(a*d,b*d,c)) return true;
        if(judge(a*b,c*b,d)) return true;
        if(judge(a*d,c*d,b)) return true;
        if(judge(a*b,d*b,c)) return true;
        if(judge(a*c,d*c,b)) return true;
        if(judge(b*a,c*a,d)) return true;
        if(judge(b*d,c*d,a)) return true;
        if(judge(b*a,d*a,c)) return true;
        if(judge(b*c,d*c,a)) return true;
        if(judge(c*a,d*a,b)) return true;
        if(judge(c*b,d*b,a)) return true;

        return false;
    }

    void fooo(int & a,int & b)
    {
        int tmp = a;
        a = b;b=tmp;
    }

    bool judge(int a,int b,int c,int target=24)
    {
        if(a%(b+c)==0) if(a/(b+c)==target) return true;
        if(b!=c) if(a%(b-c)==0) if(a/(b-c)==target) return true;
        if(a!=c) if(b%(a-c)==0) if(b/(a-c)==target) return true;
        return false;
    }

    bool judge2(int a,int b,int c,int target=24)
    {
        if(a+b*c==24) return true;
        if(b*c-a==24) return true;
        if(b+a*c==24) return true;
        if(a*c-b==24) return true;
        return false;
    }
};


int main()
{
    Solution slv;
    vector<int> cards=
    // {1,1,1,1};
    // {4,1,8,7};
    // {1,2,1,2};
    // {3,3,7,7}; //7*(3+3/7)
    // {1,5,5,5}; //5*(5-1/5)
    // {1,2,3,4};
    // {1,1,7,7}; //false
    {3,4,6,7};
    slv.fooo(cards[1],cards[2]);
    // return slv.judge3Point(1,1,1);
    return slv.judgePoint24(cards);

}