
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
    int calc_pre_height(TreeNode* root, int cur_pre_height, vector<int> &pre_height, int max_pre_height) {
        if (root == nullptr) {
            return max_pre_height;
        }
        pre_height[root->val] = max_pre_height;
        max_pre_height = max(max_pre_height, cur_pre_height);
        max_pre_height = calc_pre_height(root->left, cur_pre_height + 1, pre_height, max_pre_height);
        max_pre_height = calc_pre_height(root->right, cur_pre_height + 1, pre_height, max_pre_height);
        return max_pre_height;
    }

    int calc_post_height(TreeNode* root, int cur_post_height, vector<int> &post_height, int max_post_height) {
        if (root == nullptr) {
            return max_post_height;
        }
        post_height[root->val] = max_post_height;
        max_post_height = max(max_post_height, cur_post_height);
        max_post_height = calc_post_height(root->right, cur_post_height + 1, post_height, max_post_height);
        max_post_height = calc_post_height(root->left, cur_post_height + 1, post_height, max_post_height);
        return max_post_height;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> pre_height(100001, 0);
        vector<int> post_height(100001, 0);
        calc_pre_height(root, 0, pre_height, 0);
        calc_post_height(root, 0, post_height, 0);
        vector<int> res;
        for (auto query : queries) {
            res.push_back(max(pre_height[query], post_height[query]));
        }
        return res;
    }
};
