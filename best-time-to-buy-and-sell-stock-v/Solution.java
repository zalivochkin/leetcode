
class Solution {
    public long maximumProfit(int[] prices, int k) {
        final var n = prices.length;
        long[][][] dp = new long[n][k + 1][3];
        for (var j = 1; j <= k; ++j) {
            dp[0][j][1] = -prices[0];
            dp[0][j][2] = prices[0];
        }
        for (var i = 1; i < n; ++i) {
            for (var j = 1; j <= k; ++j) {
                dp[i][j][0] = Math.max(dp[i - 1][j][0], Math.max(dp[i - 1][j][1] + prices[i], dp[i - 1][j][2] - prices[i]));
                dp[i][j][1] = Math.max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
                dp[i][j][2] = Math.max(dp[i - 1][j][2], dp[i - 1][j - 1][0] + prices[i]);
            }
        }
        return dp[n - 1][k][0];
    }
}
