#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<utility>
#include<map>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
private:
    void addnode(vector<vector<int>> & target, Node* root ,int start)
    {
        if(target.size()<=start) target.push_back(vector<int>());
        target[start].push_back(root->val);
        for(auto ptr : root->children)
        {
            addnode(target,ptr,start+1);
        }
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root) addnode(ans,root,0);
        return ans;
    }
};


int main()
{
    Solution slv;

    Node* root = new Node();

    auto ans = slv.levelOrder(root);
    // cout<<ans;
    return 0;
}