#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int cur_t = 0;
        int max_t = 0;
        char max_c;

        for(int i=0;i<keysPressed.length();i++)
        {
            int del_t = releaseTimes[i]-cur_t;
            if(max_t<del_t)
            {
                max_t = del_t;
                max_c = keysPressed[i];
            }
            if(max_t==del_t&&keysPressed[i]>max_c)
            {
                max_c = keysPressed[i];
            }
            cur_t = releaseTimes[i];
            //cout<<"Max char is "<<max_c<<" with time "<<max_t<<endl;
        }
        return max_c;
    }
};



int main()
{   
    Solution slv;
    int n = 5;
    int vector_data[] = {9,29,49,50};
    vector<int> vec(vector_data,vector_data+n);
    string str("cbcd");
    char ans=slv.slowestKey(vec,str);
    cout<<ans<<endl;
    return 1;
}
