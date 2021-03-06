#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        int last = 0;
        int cur = 1;
        for(int i = 2;i<=n;i++)
        {
            int val = cur;
            cur = cur + last;
            last = val;
        }
        return cur;
    }
};

class Key2 { //缩小时间复杂度的快速幂算法
public:
    int fib(int n) {
        if (n < 2) {
            return n;
        }
        vector<vector<int>> q{{1, 1}, {1, 0}};
        vector<vector<int>> res = matrix_pow(q, n - 1);
        return res[0][0];
    }

    vector<vector<int>> matrix_pow(vector<vector<int>>& a, int n) {
        vector<vector<int>> ret{{1, 0}, {0, 1}};
        while (n > 0) {
            if (n & 1) {
                ret = matrix_multiply(ret, a);
            }
            n >>= 1;
            a = matrix_multiply(a, a);
        }
        return ret;
    }

    vector<vector<int>> matrix_multiply(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>> c{{0, 0}, {0, 0}};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }
        return c;
    }
};


int main()
{
    Solution slv;
    for(int i = 0;i<30;i++) cout<<slv.fib(i)<<endl;
    return 1;
}