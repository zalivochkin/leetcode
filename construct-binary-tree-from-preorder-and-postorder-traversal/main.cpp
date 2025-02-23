
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
    TreeNode* dfs(vector<int> &preorder, unordered_map<int, int> &pos, int a, int b, int c, int d) {
        if (a > b) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[a]);
        if (a == b) {
            return root;
        }
        int i = pos[preorder[a + 1]];
        int m = i - c + 1;
        root->left = dfs(preorder, pos, a + 1, a + m, c, i);
        root->right = dfs(preorder, pos, a + m + 1, b, i + 1, d - 1);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        const auto n = postorder.size();
        unordered_map<int, int> pos;
        for (auto i = 0; i < n; ++i) {
            pos[postorder[i]] = i;
        }
        return dfs(preorder, pos, 0, n - 1, 0, n - 1);
    }
};
