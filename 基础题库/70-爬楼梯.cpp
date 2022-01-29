
class Solution {
public:
    int climbStairs(int n) {
        
        if(n==1) return 1;
        if(n==2) return 2;
        return (climbStairs(n-1) + climbStairs(n-2));
    }
};

class Solution2 {
public:
    int climbStairs(int n) {
        int map[n+1];
        map[1] = 1;
        map[2] = 2;
        for (int i=3; i<=n;i++)
        {
            map[i] = map[i-1]+map[i-2];
        }
        return map[n];
    }
};

class Solution3 {
public:
    int climbStairs(int n) {
        int p = 0;
        int q = 0;
        int r = 1;
        for (int i=1; i<=n;i++)
        {
            p = q;
            q = r;
            r = p+q;
        }
        return r;
    }
};

int main()
{   
    Solution2 slv;
    return slv.climbStairs(1);
}