
import java.util.*;

class Solution {
    public String shortestCommonSupersequence(String str1, String str2) {
        final var n = str1.length();
        final var m = str2.length();
        int[][] dp = new int[n + 1][m + 1];
        for (var i = 1; i <= n; ++i) {
            for (var j = 1; j <= m; ++j) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int i = n;
        int j = m;
        StringBuilder ans = new StringBuilder();
        while (i > 0 || j > 0) {
            if (i == 0) {
                --j;
                ans.append(str2.charAt(j));
            } else if (j == 0) {
                --i;
                ans.append(str1.charAt(i));
            } else {
                if (dp[i][j] == dp[i - 1][j]) {
                    --i;
                    ans.append(str1.charAt(i));
                } else if (dp[i][j] == dp[i][j - 1]) {
                    --j;
                    ans.append(str2.charAt(j));
                } else {
                    --i;
                    ans.append(str1.charAt(i));
                    --j;
                }
            }
        }
        return ans.reverse().toString();
    }
}
