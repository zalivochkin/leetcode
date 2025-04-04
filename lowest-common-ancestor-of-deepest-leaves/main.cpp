
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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
    pair<TreeNode*, int> dfs(TreeNode* root) const {
        if (root == nullptr) {
            return {nullptr, 0};
        }
        const auto [left, deep1] = dfs(root->left);
        const auto [right, deep2] = dfs(root->right);
        if (deep1 > deep2) {
            return {left, deep1 + 1};
        }
        if (deep1 < deep2) {
            return {right, deep2 + 1};
        }
        return {root, deep1 + 1};
    }
};
