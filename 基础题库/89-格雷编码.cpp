#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        if(n==1)
        {
            ans.push_back(0);
            ans.push_back(1);
            cout<<"in n=1 case"<<endl;
            return ans;
        }
        if(n==-1)
        {
            ans.push_back(1);
            ans.push_back(0);
            cout<<"in n=-1 case"<<endl;
            return ans;
        }
        if(n>0)
        {
            vector<int> cur;
            cout<<"in n>0 case"<<endl;
            cur = grayCode(n-1);
            ans.insert(ans.end(),cur.begin(),cur.end());
            cur = grayCode(1-n);
            int t = 1;
            t = t<<(n-1);
            for(int i=0;i<cur.size();i++)
            {
                cur[i] += t;
            }
            ans.insert(ans.end(),cur.begin(),cur.end());
            cout<<"out n>0 case"<<endl;
            return ans;
        }
        if(n<0)
        {
            vector<int> cur;
            cout<<"in n<0 case"<<endl;
            cur = grayCode(-1-n);
            int t = 1;
            t = t<<(-1-n);
            for(int i=0;i<cur.size();i++)
            {
                cur[i] += t;
            }
            ans.insert(ans.end(),cur.begin(),cur.end());
            cur = grayCode(n+1);
            ans.insert(ans.end(),cur.begin(),cur.end());
            cout<<"out n<0 case"<<endl;
            return ans;
        }
        return ans;
    }
};

class Solution_2 {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1<<n);
        ans[0] = 0;
        //cout<<ans.size()<<endl;
        for(int i = 0;i<n;i++)
        {
            for(int j=(1<<i)+1;j<=(1<<(i+1));j++)
            {
                ans[j-1] = ans[(1<<(i+1))-j]+(1<<(i));
            }
        }
        return ans;
    }
};

int main()
{
    Solution_2 slv;
    vector<int> ans;
    ans = slv.grayCode(2);
    for(auto t  : ans)
    {
        cout<<t<<' ';
    }
    cout<<endl;
    return 0;
}

