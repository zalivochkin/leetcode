
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int max_sum(TreeNode* root, int &total_max) {
        if (root == nullptr) {
            return 0;
        }
        int max_single = root->val;
        int max_left = 0;
        if (root->left != nullptr) {
            max_left = max_sum(root->left, total_max);
            max_single = max(max_single, max_left + root->val);
        }
        int max_right = 0;
        if (root->right != nullptr) {
            max_right = max_sum(root->right, total_max);
            max_single = max(max_single, max_right + root->val);
        }
        total_max = max({total_max, max_single, root->val, max_left + root->val + max_right});
        return max_single;
    }

    int maxPathSum(TreeNode* root) {
        int total_max = INT_MIN;
        total_max = max(total_max, max_sum(root, total_max));
        return total_max;
    }

};
