
class Solution {
    public long getDescentPeriods(int[] prices) {
        long ans = 0;
        final var n = prices.length;
        int j;
        for (var i = 0; i < n; i = j) {
            j = i + 1;
            while (j < n && prices[j - 1] - prices[j] == 1) {
                ++j;
            }
            int cnt = j - i;
            ans += (1L + cnt) * cnt / 2;
        }
        return ans;
    }
}
