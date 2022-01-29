class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int pos = 1;
        int pospos = 0;
        int cur = 1;
        for(int i = 3;i<=n;i++)
        {
            int val = pos+pospos+cur;
            pospos = pos;
            pos = cur;
            cur = val;
        }
        return cur;
    }
};

int main()
{
    Solution slv;
    return slv.tribonacci(4);
}