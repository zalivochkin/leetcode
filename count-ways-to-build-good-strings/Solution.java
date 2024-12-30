
import java.util.*;

class Solution {
    private int dfs(int[] dp, int i, int low, int high, int zero, int one) {
        if (i > high) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        long ans = i >= low ? 1L : 0;
        ans += dfs(dp, i + zero, low, high, zero, one) + dfs(dp, i + one, low, high, zero, one);
        ans %= (long) 1e9 + 7;
        dp[i] = (int) ans;
        return dp[i];
    }

    public int countGoodStrings(int low, int high, int zero, int one) {
        int[] dp = new int[high + 1];
        Arrays.fill(dp, -1);
        return dfs(dp, 0, low, high, zero, one);
    }
}
