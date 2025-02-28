
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        const auto n = str1.size();
        const auto m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (auto i = 1; i <= n; ++i) {
            for (auto j = 1; j <= m; ++j) {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        int i = n;
        int j = m;
        string ans;
        while (i || j) {
            if (i == 0) {
                --j;
                ans += str2[j];
            } else if (j == 0) {
                --i;
                ans += str1[i];
            } else {
                if (dp[i][j] == dp[i - 1][j]) {
                    --i;
                    ans += str1[i];
                } else if (dp[i][j] == dp[i][j - 1]) {
                    --j;
                    ans += str2[j];
                } else {
                    --i;
                    ans += str1[i];
                    --j;
                }
            }
        }
        ranges::reverse(ans);
        return ans;
    }
};
