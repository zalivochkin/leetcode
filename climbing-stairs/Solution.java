
import java.util.*;

class Solution {
    public int climbStairs(int n) {
        if (n < 4) {
            return n;
        }
        int[] dp = new int[]{1, 2};
        for (int i = 2; i < n; ++i) {
            int newCount = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = newCount;
        }
        return dp[1];
    }
}
