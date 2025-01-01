
import java.util.*;

class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        var n = days[days.length - 1];
        var dp = new int[n + 1];
        final int[] valid = {1, 7, 30};
        for (int i = 1, j = 0; i <= n; ++i) {
            if (i == days[j]) {
                dp[i] = Integer.MAX_VALUE;
                for (int k = 0; k < 3; ++k) {
                    int c = costs[k];
                    int v = valid[k];
                    dp[i] = Math.min(dp[i], dp[Math.max(0, i - v)] + c);
                }
                ++j;
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[n];
    }
}
