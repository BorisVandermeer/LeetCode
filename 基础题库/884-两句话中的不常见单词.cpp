
#include<bits/stdc++.h>

using namespace std;

//C++17 needed
class Solution {
public:
    vector<string> uncommonFromSentences_key(string s1, string s2) {
        unordered_map<string, int> freq;
        stringstream ss1(s1);
        stringstream ss2(s2);
        string word;
        while(ss1>>word) ++freq[move(word)];
        while(ss2>>word) ++freq[move(word)];

        vector<string> ans;
        
        // for(auto [str,occ]:freq) if(occ==1) ans.push_back(str); // C++17 Needed
        for(auto & it:freq) if(it.second==1) ans.push_back(it.first); //C++11 Needed
        return ans;
    }
};

int main()
{
    Solution slv;
    string s1 = "This is an apple";
    string s2 = "This is a pear";
    vector<string> s = slv.uncommonFromSentences_key(s1,s2);
    for(auto str:s)
    {
        cout<<str<<endl;
    }
    return 0;
}