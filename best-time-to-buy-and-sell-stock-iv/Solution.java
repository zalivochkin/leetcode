
import java.util.*;

class Solution {
    public int maxProfit(int k, int[] prices) {
        final var n = prices.length;
        int[][] dp = new int[k + 1][2];
        for (var i = 1; i <= k; ++i) {
            dp[i][1] = -prices[0];
        }
        for (var i = 1; i < n; ++i) {
            for (int j = k; j > 0; --j) {
                dp[j][0] = Math.max(dp[j][1] + prices[i], dp[j][0]);
                dp[j][1] = Math.max(dp[j - 1][0] - prices[i], dp[j][1]);
            }
        }
        return dp[k][0];
    }
}
