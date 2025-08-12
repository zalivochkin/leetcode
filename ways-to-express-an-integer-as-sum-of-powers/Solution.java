
class Solution {
    public int numberOfWays(int n, int x) {
        final int mod = (int) 1e9 + 7;
        int[][] dp = new int[n + 1][n + 1];
        dp[0][0] = 1;
        for (var i = 1; i <= n; ++i) {
            var k = (long) Math.pow(i, x);
            for (var j = 0; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (k <= j) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - (int) k]) % mod;
                }
            }
        }
        return dp[n][n];
    }
}
