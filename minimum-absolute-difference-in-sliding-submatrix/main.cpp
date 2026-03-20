
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        const auto n = grid.size();
        const auto m = grid[0].size();
        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1, 0));
        for (int i = 0; i <= n - k; ++i) {
            for (int j = 0; j <= m - k; ++j) {
                vector<int> nums;
                for (int x = i; x < i + k; ++x) {
                    for (int y = j; y < j + k; ++y) {
                        nums.push_back(grid[x][y]);
                    }
                }
                ranges::sort(nums);
                int d = numeric_limits<int>::max();
                const auto k = nums.size();
                for (auto t = 1; t < k; ++t) {
                    if (nums[t] != nums[t - 1]) {
                        d = min(d, abs(nums[t] - nums[t - 1]));
                    }
                }
                ans[i][j] = (d == numeric_limits<int>::max()) ? 0 : d;
            }
        }
        return ans;
    }
};
