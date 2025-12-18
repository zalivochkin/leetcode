
class Solution {
    public long maxProfit(int[] prices, int[] strategy, int k) {
        final var n = prices.length;
        long[] s = new long[n + 1];
        long[] t = new long[n + 1];
        for (var i = 1; i <= n; i++) {
            int a = prices[i - 1];
            int b = strategy[i - 1];
            s[i] = s[i - 1] + a * b;
            t[i] = t[i - 1] + a;
        }
        long ans = s[n];
        for (var i = k; i <= n; i++) {
            ans = Math.max(ans, s[n] - (s[i] - s[i - k]) + (t[i] - t[i - k / 2]));
        }
        return ans;
    }
}
