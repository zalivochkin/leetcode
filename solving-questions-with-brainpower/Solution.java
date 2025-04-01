
class Solution {
    public long mostPoints(int[][] questions) {
        final var n = questions.length;
        long[] dp = new long[n + 1];
        for (int i = n - 1; i >= 0; --i) {
            int j = i + questions[i][1] + 1;
            dp[i] = Math.max(dp[i + 1], questions[i][0] + (j > n ? 0 : dp[j]));
        }
        return dp[0];
    }
}
