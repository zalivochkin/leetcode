
class Solution {
    public int[] smallestSubarrays(int[] nums) {
        final var n = nums.length;
        int[] ans = new int[n];
        int[] dp = new int[32];
        Arrays.fill(dp, -1);
        for (int i = n - 1; i >= 0; --i) {
            int t = 1;
            for (var j = 0; j < 32; ++j) {
                if (((nums[i] >> j) & 1) == 1) {
                    dp[j] = i;
                } else if (dp[j] != -1) {
                    t = Math.max(t, dp[j] - i + 1);
                }
            }
            ans[i] = t;
        }
        return ans;
    }
}
