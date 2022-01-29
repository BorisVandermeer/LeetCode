#include<iostream>
#include<string>
#include<vector>

using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
        string filename;
        vector<string> splitpath;
        for(char c : path)
        {
            if(c=='/')
            {
                splitpath.push_back(filename);
                filename.clear();
            }
            else
            {
                filename += c;
            }
        }
        splitpath.push_back(filename);
        
        vector<string> splitpath_fin;
        for(string str : splitpath)
        {
            if(str == "..")
            {
                if(!splitpath_fin.empty()) splitpath_fin.pop_back();
            }
            else if(!str.empty()&&str!=".")
            {
                splitpath_fin.push_back(str);
            }
            if(str =="...") cout<<"ok"<<endl;
        }
        string realpath;
        if(splitpath_fin.empty()) return "/";
        for(string str : splitpath_fin)
        {
            realpath += '/';
            realpath += str;
        }
        return realpath;
    }
};

int main()
{
    Solution solve;
    string one("/home/str/sss/..././../../qwe");
    cout<<solve.simplifyPath(one)<<endl;
    return 1;
}