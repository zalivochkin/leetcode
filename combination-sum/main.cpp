
class Solution {
public:
    void dfs(vector<int>& candidates, int target, int cur_indx, vector<vector<int>> &res, vector<int> &candidate) {
        if (target == 0) {
            res.push_back(candidate);
            return;
        }
        const auto n = candidates.size();
        for (auto i = cur_indx; i < n; ++i) {
            if (candidates[i] <= target) {
                candidate.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], i, res, candidate);
                candidate.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> candidate;
        dfs(candidates, target, 0, res, candidate);
        return res;
    }
};
