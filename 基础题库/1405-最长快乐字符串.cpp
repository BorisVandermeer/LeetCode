#include<iostream>
#include<string>
#include<vector>


using namespace std;

// 还算是有点有趣的一个思路
// 先给三个玩意排个序，不妨记a的数量最多，b其次，c最少
// 首先把多余的a去掉
// 先考虑a不得不两个两个(a>b+c+1)的情况，不停减少a的同时，也相应减少b和c，确保b一定比c多
// 之后同时减少c和a让a和b对齐，此时a<=b+c+1,所以一定是可以对其的。
// 然后同时减少a,b,c让c变成0
// 然后同时减少a和b，让b变成0
// 最后a可能还剩一个，就让最后一个是a好了
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans;
        pair<int,char> pair1;
        pair<int,char> pair2;
        pair<int,char> pair3;
        if(a>=b&&a>=c)       { pair1=make_pair(a,'a'); if(b>c){ pair2=make_pair(b,'b');pair3 = make_pair(c,'c');} else {pair3=make_pair(b,'b');pair2 = make_pair(c,'c');}}
        else if(b>=c&&b>=a)  { pair1=make_pair(b,'b'); if(a>c){ pair2=make_pair(a,'a');pair3 = make_pair(c,'c');} else {pair3=make_pair(a,'a');pair2 = make_pair(c,'c');}}
        else                 { pair1=make_pair(c,'c'); if(b>a){ pair2=make_pair(b,'b');pair3 = make_pair(a,'a');} else {pair3=make_pair(b,'b');pair2 = make_pair(a,'a');}}

        int line = (pair2.first+pair3.first)*2+2;
        if(pair1.first>line) pair1.first = line;
        ans.reserve(pair1.first+pair2.first+pair3.first);
        while(pair1.first>pair2.first+pair3.first+1)
        {
            ans+=pair1.second;
            ans+=pair1.second;
            pair1.first-=2;            
            if(pair2.first==0) return ans;
            if(pair2.first==pair3.first)
            {
                ans+=pair3.second;
                pair3.first--;
            }
            else
            {
                ans+=pair2.second;
                pair2.first--;
            }
        }
        while(pair1.first>pair2.first+1)
        {
            ans+=pair1.second;
            pair1.first--;
            ans+=pair3.second;
            pair3.first--;
        }
        while(pair3.first>0)
        {
            ans+=pair1.second;
            pair1.first--;
            ans+=pair2.second;
            pair2.first--;
            ans+=pair3.second;
            pair3.first--;
        }
        while(pair2.first>0)
        {
            ans+=pair1.second;
            pair1.first--;
            ans+=pair2.second;
            pair2.first--;
        }
        if(pair1.first==1) ans+=pair1.second;
        return ans;
       
    }
};

// 官方解答，C++17 一系列问题报错
// class Solution_Key1 {
// public:
//     string longestDiverseString(int a, int b, int c) {
//         string res;
//         vector<pair<int, char>> arr = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        
//         while (true) {
//             sort(arr.begin(), arr.end(), [](const pair<int, char> & p1, const pair<int, char> & p2) {
//                 return p1.first > p2.first;
//             });
//             bool hasNext = false;
//             for (auto & [freq, ch] : arr) {
//                 int m = res.size();
//                 if (freq <= 0) {
//                     break;
//                 }
//                 if (m >= 2 && res[m - 2] == ch && res[m - 1] == ch) {
//                     continue;
//                 }
//                 hasNext = true;
//                 res.push_back(ch);
//                 freq--;
//                 break;
//             }
//             if (!hasNext) {
//                 break;
//             }
//         }
      
//         return res;
//     }
// };


int main()
{
    Solution slv;
    int a = 4;
    int b = 2;
    int c = 1;
    string ans = slv.longestDiverseString(a,b,c);
    cout<<ans<<endl;
    return 1;
}