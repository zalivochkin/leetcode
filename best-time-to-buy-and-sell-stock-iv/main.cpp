
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        auto n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        for (int i = n - 1; i >= 0; i--) {
            for (auto j = 0; j < 2; j++) {
                for (int m = k; m >= 1; m--) {
                    if (j == 0) {
                        dp[i][j][m] = max(dp[i + 1][1][m] - prices[i], dp[i + 1][0][m]);
                    } else { //sell
                        dp[i][j][m] = max(dp[i + 1][0][m - 1] + prices[i], dp[i + 1][1][m]);
                    }
                }
            }
        }
        return dp[0][0][k];
    }
};
