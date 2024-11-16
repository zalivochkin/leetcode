
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }
        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }
        if (root1->val != root2->val) {
            return false;
        }
        if (!flipEquiv(root1->left, root2->left)) {
            swap(root2->left, root2->right);
            if (!flipEquiv(root1->left, root2->left)) {
                return false;
            }
        }
        if (!flipEquiv(root1->right, root2->right)) {
            swap(root2->left, root2->right);
            if (!flipEquiv(root1->right, root2->right)) {
                return false;
            }
        }
        return true;
    }
};
