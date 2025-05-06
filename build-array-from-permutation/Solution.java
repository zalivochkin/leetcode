
class Solution {
    public int[] buildArray(int[] nums) {
        final var n = nums.length;
        int[] ans = new int[n];
        for (var i = 0; i < n; ++i) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
}
