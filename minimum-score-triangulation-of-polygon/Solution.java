
class Solution {
    public int minScoreTriangulation(int[] values) {
        final var n = values.length;
        int[][] dp = new int[n][n];
        for (var l = 3; l <= n; ++l) {
            for (var i = 0; i + l - 1 < n; ++i) {
                int j = i + l - 1;
                dp[i][j] = 1 << 30;
                for (var k = i + 1; k < j; ++k) {
                    dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[k] * values[j]);
                }
            }
        }
        return dp[0][n - 1];
    }
}
