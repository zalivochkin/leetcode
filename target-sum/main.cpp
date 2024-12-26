
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        long long s = accumulate(nums.begin(), nums.end(), 0);
        if (s < target || (s - target) % 2) {
            return 0;
        }
        const auto m = nums.size();
        long long n = (s - target) / 2;
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
        f[0][0] = 1;
        for (auto i = 1; i <= m; ++i) {
            for (auto j = 0; j <= n; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= nums[i - 1]) {
                    f[i][j] += f[i - 1][j - nums[i - 1]];
                }
            }
        }
        return f[m][n];
    }
};
