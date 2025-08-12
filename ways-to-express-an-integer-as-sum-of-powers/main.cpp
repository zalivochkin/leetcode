
class Solution {
public:
    int numberOfWays(int n, int x) {
        const int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for (auto i = 1; i <= n; ++i) {
            auto k = (long long) pow(i, x);
            for (auto j = 0; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (k <= j) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
                }
            }
        }
        return dp[n][n];
    }
};
