
import java.util.*;

class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);
        final var n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        int maxIdx = 0;
        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            if (dp[maxIdx] < dp[i]) {
                maxIdx = i;
            }
        }
        int m = dp[maxIdx];
        List<Integer> ans = new ArrayList<>();
        for (int i = maxIdx; m > 0; --i) {
            if (nums[maxIdx] % nums[i] == 0 && dp[i] == m) {
                ans.add(nums[i]);
                maxIdx = i;
                --m;
            }
        }
        return ans;
    }
}
