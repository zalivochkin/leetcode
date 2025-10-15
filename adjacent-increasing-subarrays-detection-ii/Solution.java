
class Solution {
    public int maxIncreasingSubarrays(List<Integer> nums) {
        int ans = 0;
        int pre = 0;
        int cur = 0;
        final var n = nums.size();
        for (var i = 0; i < n; ++i) {
            ++cur;
            if (i == n - 1 || nums.get(i) >= nums.get(i + 1)) {
                ans = Math.max(ans, Math.max(cur / 2, Math.min(pre, cur)));
                pre = cur;
                cur = 0;
            }
        }
        return ans;
    }
}
