
class Solution {
    public int countPartitions(int[] nums, int k) {
        final var mod = (int) 1e9 + 7;
        TreeMap<Integer, Integer> sl = new TreeMap<>();
        final var n = nums.length;
        int[] dp1 = new int[n + 1];
        int[] dp2 = new int[n + 1];
        dp1[0] = 1;
        dp2[0] = 1;
        int l = 1;
        for (int r = 1; r <= n; r++) {
            sl.merge(nums[r - 1], 1, Integer::sum);
            while (sl.lastKey() - sl.firstKey() > k) {
                if (sl.merge(nums[l - 1], -1, Integer::sum) == 0) {
                    sl.remove(nums[l - 1]);
                }
                ++l;
            }
            dp1[r] = (dp2[r - 1] - (l >= 2 ? dp2[l - 2] : 0) + mod) % mod;
            dp2[r] = (dp2[r - 1] + dp1[r]) % mod;
        }
        return dp1[n];
    }
}
