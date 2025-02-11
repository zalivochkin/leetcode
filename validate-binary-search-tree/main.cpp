
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
    bool dfs(TreeNode* root, TreeNode* &prev) {
        if (!root) {
            return true;
        }
        if (!dfs(root->left, prev)) {
            return false;
        }
        if (prev && prev->val >= root->val) {
            return false;
        }
        prev = root;
        return dfs(root->right, prev);
    }

    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return dfs(root, prev);
    }
};
