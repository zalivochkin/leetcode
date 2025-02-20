
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
    TreeNode* dfs(vector<int> &nums, int lft, int rght) {
        if (lft > rght) {
            return nullptr;
        }
        int mid = lft + (rght - lft) / 2;
        auto left = dfs(nums, lft, mid - 1);
        auto right = dfs(nums, mid + 1, rght);
        return new TreeNode(nums[mid], left, right);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }
};
