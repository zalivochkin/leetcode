
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root != nullptr) {
            if (root->left == nullptr && root->right == nullptr) {
                res.push_back(to_string(root->val));
            }
            if (root->left != nullptr) {
                const auto left_paths = binaryTreePaths(root->left);
                for (const auto &left_path : left_paths) {
                    res.push_back(to_string(root->val) + "->" + left_path);
                }
            }
            if (root->right != nullptr) {
                const auto right_paths = binaryTreePaths(root->right);
                for (const auto &right_path : right_paths) {
                    res.push_back(to_string(root->val) + "->" + right_path);
                }
            }
        }
        return res;
    }
};
