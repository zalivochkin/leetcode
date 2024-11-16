
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        stack<TreeNode*> level_nodes;
        stack<TreeNode*> next_level_nodes;
        map<long long, int> largest_sums;
        level_nodes.push(root);
        while (!level_nodes.empty()) {
            long long cur_sum = 0;
            while (!level_nodes.empty()) {
                TreeNode *node = level_nodes.top();
                level_nodes.pop();
                cur_sum += node->val;
                if (node->left != nullptr) {
                    next_level_nodes.push(node->left);
                }
                if (node->right != nullptr) {
                    next_level_nodes.push(node->right);
                }
            }
            largest_sums[cur_sum] += 1;
            swap(level_nodes, next_level_nodes);
        }
        for (auto it = largest_sums.rbegin(); it != largest_sums.rend(); ++it) {
            auto [sum, cnt] = *it;
            k -= cnt;
            if (k <= 0) {
                return sum;
            }
        }
        return -1;
    }
};
