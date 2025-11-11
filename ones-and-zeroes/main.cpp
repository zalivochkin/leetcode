
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (const auto &str : strs) {
            auto [a, b] = count(str);
            for (int i = m; i >= a; --i) {
                for (int j = n; j >= b; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - a][j - b] + 1);
                }
            }
        }
        return dp[m][n];
    }

    pair<int, int> count(const string &str) {
        int a = count_if(str.begin(), str.end(), [](char c) { return c == '0'; });
        return {a, str.size() - a};
    }
};
