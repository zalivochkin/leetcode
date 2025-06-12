
class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int ans = Math.abs(nums[0] - nums[nums.length - 1]);
        final var n = nums.length;
        for (var i = 0; i + 1 < n; ++i) {
            ans = Math.max(ans, Math.abs(nums[i] - nums[i + 1]));
        }
        return ans;
    }
}
