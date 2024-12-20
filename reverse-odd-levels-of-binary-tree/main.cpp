
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        stack<int> st;
        vector<TreeNode*> v(16385);
        while (!q.empty()) {
            auto n = q.size();
            for (auto i = 0; i < n; ++i) {
                auto node = q.front();
                q.pop();
                if (level % 2 != 0) {
                    v[i] = node;
                    st.push(node->val);
                }
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            if (level % 2 != 0) {
                for (auto i = 0; i < n; ++i) {
                    v[i]->val = st.top();
                    st.pop();
                }
            }
            ++level;
        }
        return root;
    }
};
