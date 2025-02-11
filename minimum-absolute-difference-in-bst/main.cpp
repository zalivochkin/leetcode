
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
    void dfs(TreeNode* root, long long &res, long long &pre) {
        if (!root) {
            return;
        }
        dfs(root->left, res, pre);
        res = min(res, root->val - pre);
        pre = root->val;
        dfs(root->right, res, pre);
    }

    int getMinimumDifference(TreeNode* root) {
        long long res = numeric_limits<int>::max();
        long long pre = numeric_limits<int>::min();
        dfs(root, res, pre);
        return res;
    }
};
