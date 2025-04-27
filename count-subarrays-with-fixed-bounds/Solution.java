
class Solution {
    public long countSubarrays(int[] nums, int minK, int maxK) {
        long ans = 0;
        int j1 = -1;
        int j2 = -1;
        int k = -1;
        final var n = nums.length;
        for (var i = 0; i < n; ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                k = i;
            }
            if (nums[i] == minK) {
                j1 = i;
            }
            if (nums[i] == maxK) {
                j2 = i;
            }
            ans += Math.max(0, Math.min(j1, j2) - k);
        }
        return ans;
    }
}
