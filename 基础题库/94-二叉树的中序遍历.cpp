#include<vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> m,p;
        if(root == NULL) return m;
        m = inorderTraversal(root->left);
        p = inorderTraversal(root->right);
        m.push_back(root->val);
        m.insert(m.end(),p.begin(),p.end());
        return m;
    }
};

int main()
{   
    Solution slv;
    return 1;
}