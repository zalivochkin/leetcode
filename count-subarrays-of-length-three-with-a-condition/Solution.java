
class Solution {
    public int countSubarrays(int[] nums) {
        final var n = nums.length;
        int res = 0;
        for (var i = 2; i < n; ++i) {
            if ((nums[i - 2] + nums[i]) * 2 == nums[i - 1]) {
                ++res;
            }
        }
        return res;
    }
}
