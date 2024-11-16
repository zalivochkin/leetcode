
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        const auto n = matrix.size();
        const auto m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int res = 0;
        for (auto i = 1; i <= n; ++i) {
            for (auto j = 1; j <= m; ++j) {
                if (matrix[i - 1][j - 1] == 1) {
                    dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
                    res += dp[i][j];
                }
            }
        }
        return res;
    }
};
