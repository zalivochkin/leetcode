
class Solution {
public:
    const int mod = 1e9 + 7;

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const auto n = grid.size();
        const auto m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k)));
        dp[0][0][grid[0][0] % k] = 1;
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                for (auto s = 0; s < k; ++s) {
                    int t = ((s - grid[i][j] % k) + k) % k;
                    if (i) {
                        dp[i][j][s] += dp[i - 1][j][t];
                    }
                    if (j) {
                        dp[i][j][s] += dp[i][j - 1][t];
                    }
                    dp[i][j][s] %= mod;
                }
            }
        }
        return dp[n - 1][m - 1][0];
    }
};
