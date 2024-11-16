
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        root->val = 0;
        while (!q.empty()) {
            unordered_map<TreeNode*, long long> mp;
            auto n = q.size();
            long long total_sum = 0;
            for (auto i = 0; i < n; ++i) {
                auto node = q.front();
                q.pop();
                q.push(node);
                if (node->left != nullptr) {
                    mp[node] += node->left->val;
                }
                if (node->right != nullptr) {
                    mp[node] += node->right->val;
                }
                total_sum += mp[node];
            }
            for (auto i = 0; i < n; ++i) {
                auto node = q.front();
                q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                    node->left->val = (total_sum - mp[node]);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                    node->right->val = (total_sum - mp[node]);
                }
            }
        }
        return root;
    }
};
