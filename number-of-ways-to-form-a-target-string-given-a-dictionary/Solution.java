
import java.util.*;

class Solution {
        var n = words[0].length();
        var m = target.length();
        var mod = 1e9 + 7;
        long[][] dp = new long[m + 1][n + 1];
        Arrays.fill(dp[0], 1);
        int[][] cnt = new int[n][26];
        for (var word : words) {
            for (var i = 0; i < n; ++i) {
                cnt[i][word.charAt(i) - 'a'] += 1;
            }
        }
        for (var i = 1; i <= m; ++i) {
            for (var j = 1; j <= n; ++j) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1] * cnt[j - 1][target.charAt(i - 1) - 'a'];
                dp[i][j] %= mod;
            }
        }
        return (int) dp[m][n];
}
