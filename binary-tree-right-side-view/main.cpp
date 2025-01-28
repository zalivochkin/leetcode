
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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<TreeNode*> lev;
        vector<int> res;
        lev.push_back(root);
        while (!lev.empty()) {
            res.push_back(lev[lev.size() - 1]->val);
            vector<TreeNode*> next_lev;
            for (auto i = 0; i < lev.size(); ++i) {
                if (lev[i]->left != nullptr) {
                    next_lev.push_back(lev[i]->left);
                }
                if (lev[i]->right != nullptr) {
                    next_lev.push_back(lev[i]->right);
                }
            }
            swap(lev, next_lev);
        }
        return res;
    }
};
