
class Solution {
public:
    double dfs(int i, int j, vector<vector<double>> &dp) {
        if (i <= 0 && j <= 0) {
            return 0.5;
        }
        if (i <= 0) {
            return 1;
        }
        if (j <= 0) {
            return 0;
        }
        if (dp[i][j] > 0) {
            return dp[i][j];
        }
        double ans = 0.25 * (dfs(i - 4, j, dp) + dfs(i - 3, j - 1, dp) + dfs(i - 2, j - 2, dp) + dfs(i - 1, j - 3, dp));
        dp[i][j] = ans;
        return ans;
    }

    double soupServings(int n) {
        vector<vector<double>> dp(200, vector<double>(200, 0));
        return n > 4800 ? 1 : dfs((n + 24) / 25, (n + 24) / 25, dp);
    }
};
