
class Solution {
    public int bestClosingTime(String customers) {
        final var n = customers.length();
        int[] s = new int[n + 1];
        for (var i = 0; i < n; ++i) {
            if (customers.charAt(i) == 'Y') {
                s[i + 1] = s[i] + 1;
            } else {
                s[i + 1] = s[i];
            }
        }
        int ans = 0;
        int cost = Integer.MAX_VALUE;
        for (var j = 0; j <= n; ++j) {
            int t = j - s[j] + s[n] - s[j];
            if (cost > t) {
                ans = j;
                cost = t;
            }
        }
        return ans;
    }
}
