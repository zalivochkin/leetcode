
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) {
            return nullptr;
        }
        if (root->val == key) {
            return deleteRoot(root);
        }
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }

private:
    TreeNode* deleteRoot(TreeNode* root) {
        if(root->right == nullptr) {
            return root->left;
        } else if(root->left == nullptr) {
            return root->right;
        } else if (root->right->left == nullptr) {
            root->right->left = root->left;
            return root->right;
        }
        TreeNode* new_root = detachMostLeft(root->right);
        new_root->left = root->left;
        new_root->right = root->right;
        return new_root;
    }

    TreeNode* detachMostLeft(TreeNode* root) {
        if(root == nullptr) {
            return nullptr;
        }
        if (root->left == nullptr) {
            return root;
        }
        if (root->left->left == nullptr) {
            TreeNode* new_root = root->left;
            root->left = nullptr;
            return new_root;
        }
        return detachMostLeft(root->left);
    }
};
