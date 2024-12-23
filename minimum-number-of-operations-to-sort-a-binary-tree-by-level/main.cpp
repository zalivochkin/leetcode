
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
    int min_swaps(vector<int>& temp) {
        auto n = temp.size();
        vector<int> alls(temp.begin(), temp.end());
        sort(alls.begin(), alls.end());
        unordered_map<int, int> mp;
        int cnt = 0;
        for (auto i = 0; i < n; ++i) {
            mp[alls[i]] = i;
        }
        for (auto i = 0; i < n; ++i) {
            temp[i] = mp[temp[i]];
        }
        for (auto i = 0; i < n; ++i) {
            while (temp[i] != i) {
                swap(temp[i], temp[temp[i]]);
                ++cnt;
            }
        }
        return cnt;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        auto n = q.size();
        auto node = q.front();
        while (!q.empty()) {
            vector<int> t;
            n = q.size();
            for (auto i = 0; i < n; ++i) {
                node = q.front();
                q.pop();
                t.emplace_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            ans += min_swaps(t);
        }
        return ans;
    }
};
