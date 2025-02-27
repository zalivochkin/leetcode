
import java.util.*;

class Solution {
    public int lenLongestFibSubseq(int[] arr) {
        int n = arr.length;
        var dp = new int[n][n];
        Map<Integer, Integer> mp = new HashMap<>();
        for (var i = 0; i < n; ++i) {
            mp.put(arr[i], i);
            for (var j = 0; j < i; ++j) {
                dp[i][j] = 2;
            }
        }
        int ans = 0;
        for (var i = 2; i < n; ++i) {
            for (var j = 1; j < i; ++j) {
                var k = mp.get(arr[i] - arr[j]);
                if (k != null && k < j) {
                    dp[i][j] = Math.max(dp[i][j], dp[j][k] + 1);
                    ans = Math.max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
}
