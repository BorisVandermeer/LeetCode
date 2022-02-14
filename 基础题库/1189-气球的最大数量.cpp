#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string & text) {
        vector<int> vec(5,0);
        for(auto chr : text)
        {
            if(chr=='l') vec[0]++;
            else if(chr=='o') vec[1]++;
            else if(chr=='b') vec[2]++;
            else if(chr=='a') vec[3]++;
            else if(chr=='n') vec[4]++;
        }
        vec[0]/=2;
        vec[1]/=2;
        int tmp=vec[0];
        if(tmp<vec[1]) tmp=vec[1];
        if(tmp<vec[2]) tmp=vec[2];
        if(tmp<vec[3]) tmp=vec[3];
        if(tmp<vec[4]) tmp=vec[4];
        return tmp;

    }
};

int main()
{
    Solution slv;
    return 0;
}