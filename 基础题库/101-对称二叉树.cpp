struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 递归算法
class Solution_1 {
private:
    bool isSymmetric2(TreeNode* root1,TreeNode* root2)
    {
        if(!root1&&!root2) return true;
        if(!root1||!root2) return false;
        if(root1->val!=root2->val) return false;
        return isSymmetric2(root1->left,root2->right)&&isSymmetric2(root1->right,root2->left);
        return 1;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric2(root->left,root->right);
    }
};

//

int main()
{
    if(nullptr) return 0;
    if(nullptr||1) return 1;
    return 2;
}