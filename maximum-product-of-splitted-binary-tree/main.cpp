
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
    long long sum(const TreeNode * const root) {
        if (!root) {
            return 0;
        }
        return root->val + sum(root->left) + sum(root->right);
    }

    long long dfs(const TreeNode * const root, const long long summ, long long &ans) {
        if (!root) {
            return 0;
        }
        long long t = root->val + dfs(root->left, summ, ans) + dfs(root->right, summ, ans);
        if (t < summ) {
            ans = max(ans, t * (summ - t));
        }
        return t;
    }

    int maxProduct(TreeNode* root) {
        long long ans = 0;
        const int mod = 1e9 + 7;
        long long summ = sum(root);
        dfs(root, summ, ans);
        return ans % mod;
    }
};
