
class Solution {
public:
    void dfs(vector<vector<int>> &ans, vector<int> &tmp_ans, int n, int k, int i) {
        if (tmp_ans.size() == k) {
            ans.emplace_back(tmp_ans);
            return;
        }
        if (i > n) {
            return;
        }
        tmp_ans.emplace_back(i);
        dfs(ans, tmp_ans, n, k, i + 1);
        tmp_ans.pop_back();
        dfs(ans, tmp_ans, n, k, i + 1);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> tmp_ans;
        dfs(ans, tmp_ans, n, k, 1);
        return ans;
    }
};
