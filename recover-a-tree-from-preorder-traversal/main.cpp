
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
    TreeNode* recoverFromPreorder(string traversal) {
        const auto n = traversal.size();
        stack<TreeNode*> stack;
        for (auto i = 0; i < n; ++i) {
            int depth = 0;
            while (i < traversal.length() && traversal[i] == '-') {
                depth++;
                i++;
            }
            int number = 0;
            while (i < n && isdigit(traversal[i])) {
                number = number * 10 + traversal[i] - '0';
                i++;
            }
            --i;
            bool wentBack = stack.size() > depth;
            while (stack.size() > depth) {
                stack.pop();
            }
            auto* current = new TreeNode(number);
            if (!stack.empty()) {
                TreeNode* top = stack.top();
                if (wentBack) {
                    top->right = current;
                } else {
                    top->left = current;
                }
            }
            stack.push(current);
        }
        while (stack.size() > 1) {
            stack.pop();
        }
        return stack.top();
    }
};
