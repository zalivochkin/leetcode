
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const auto n = words[0].size();
        const auto m = target.size();
        const auto mod = static_cast<int>(1e9 + 7);
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        fill(dp[0].begin(), dp[0].end(), 1);
        vector<vector<int>> cnt(n, vector<int>(26));
        for (const auto &word : words) {
            for (auto i = 0; i < n; ++i) {
                cnt[i][word[i] - 'a'] += 1;
            }
        }
        for (auto i = 1; i <= m; ++i) {
            for (auto j = 1; j <= n; ++j) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1] * cnt[j - 1][target[i - 1] - 'a'];
                dp[i][j] %= mod;
            }
        }
        return static_cast<int>(dp[m][n]);
    }
};
