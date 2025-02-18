
class Solution {
public:
    void dfs(vector<int> &nums, vector<vector<int>> &ans, vector<int> &tmp_ans, vector<bool> &vis, int i) {
        const auto n = nums.size();
        if (i == n) {
            ans.emplace_back(tmp_ans);
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (!vis[j]) {
                vis[j] = true;
                tmp_ans[i] = nums[j];
                dfs(nums, ans, tmp_ans, vis, i + 1);
                vis[j] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        const auto n = nums.size();
        vector<vector<int>> ans;
        vector<int> tmp_ans(n);
        vector<bool> vis(n);
        dfs(nums, ans, tmp_ans, vis, 0);
        return ans;
    }
};
