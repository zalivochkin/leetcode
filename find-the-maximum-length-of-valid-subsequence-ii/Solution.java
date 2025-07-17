
class Solution {
    public int maximumLength(int[] nums, int k) {
        int[][] dp = new int[k][k];
        int ans = 0;
        for (var num : nums) {
            num %= k;
            for (var j = 0; j < k; ++j) {
                int y = (j - num + k) % k;
                dp[num][y] = dp[y][num] + 1;
                ans = Math.max(ans, dp[num][y]);
            }
        }
        return ans;
    }
}
