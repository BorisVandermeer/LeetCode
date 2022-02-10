#include<iostream>
#include<vector>
#include<string>
#include<math.h>

using  namespace std;

template<typename T>
void showvec(vector<T> vec,int flag=1)
{
    for(auto & a:vec) cout<<' '<<a;
    if(flag==1) cout<<endl;
    if(flag==2) cout<<", ";
}


class Solution {
    vector<int> primenums = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    string strgen(int a,int b)
    {
        string tmp;
        while (b!=0)
        {
            tmp+= ('0'+b%10);
            b = b/10;
        }
        tmp += '/';
        while(a!=0)
        {
            tmp+=('0'+a%10);
            a=a/10;
        }
        int line = tmp.size()/2;
        for(int i=0;i<line;i++)
        {
            char t = tmp[i];
            tmp[i] = tmp[tmp.size()-i-1];
            tmp[tmp.size()-i-1]=t;
        }
        return tmp;
    }
    void push(int n,vector<string> & ans)
    {
        int s = n/2+1;
        int idx = 0;
        while(primenums[idx]<s) idx++;
        vector<int> q;
        for(int i=0;i<=idx;i++) if(n%primenums[i]==0) q.push_back(primenums[i]);
        vector<int> p(q.size(),0);
        for(int i=1;i<n;i++)
        {
            bool flag = 1;
            for(int j=0;j<p.size();j++)
            {
                p[j]++;
                if(p[j]==q[j])
                {
                    p[j] = 0;
                    flag = 0;
                }
            }
            if(flag) ans.push_back(strgen(i,n));
        }
        return;
    }
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for(int i=2;i<=n;i++) push(i,ans);
        return ans;
    }
};


// __gcd 是GNU 内部函数
// class Solution_Key {
// public:
//     vector<string> simplifiedFractions(int n) {
//         vector<string> ans;
//         for (int denominator = 2; denominator <= n; ++denominator) {
//             for (int numerator = 1; numerator < denominator; ++numerator) {
//                 if (__gcd(numerator, denominator) == 1) {
//                     ans.emplace_back(to_string(numerator) + "/" + to_string(denominator));
//                 }
//             }
//         }
//         return ans;
//     }
// };
int main()
{
    Solution slv;
    vector<string> ans = slv.simplifiedFractions(7);
    // cout<<slv.strgen(12,3)<<endl;
    showvec<string>(ans);
    return 0;
}