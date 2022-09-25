#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<queue>
#include<utility>
#include<stack>
#include<map>
#include<unordered_map>
#include<algorithm>


using namespace std;

template<typename T=int>
void showvec(vector<T> vec,int D1Type=1,int D0Type = 3)
{
    if(D0Type = 2) for(auto & a:vec) cout<<a<<", ";
    else if(D0Type = 3) for(auto & a:vec) cout<<a<<' ';
    else for(auto & a:vec) cout<<a;
    if(D1Type==1) cout<<endl;
    if(D1Type==2) cout<<", ";
    if(D1Type==3) cout<<" ";
}

class Solution {
    int getdata(vector<int>* vecptr,int idx)
    {
        int s = vecptr->size();
        if(idx>=s) return getdata(vecptr,idx-s);
        if(idx<0) return getdata(vecptr,idx+s);
        return (*vecptr)[idx];
    }
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans(code.size(),0);
        if(k>=0)
        {
            for(int i=0;i<code.size();i++)
            {
                for(int j=1;j<=k;j++)
                {
                    ans[i]+=getdata(&code,i+j);
                }
            }
        }
        else{
            for(int i=0;i<code.size();i++)
            {
                for(int j=1;j<=-k;j++)
                {
                    ans[i]+=getdata(&code,i-j);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution slv;
    vector<int> code = {5,7,1,4};
    int k = 3;

    auto ans = slv.decrypt(code,k);
    showvec(ans);
    return 0;
}