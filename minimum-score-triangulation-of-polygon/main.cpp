
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        const auto n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (auto l = 3; l <= n; ++l) {
            for (auto i = 0; i + l - 1 < n; ++i) {
                int j = i + l - 1;
                dp[i][j] = 1 << 30;
                for (auto k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[k] * values[j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
