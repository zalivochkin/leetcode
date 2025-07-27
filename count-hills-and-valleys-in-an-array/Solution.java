
class Solution {
    public int countHillValley(int[] nums) {
        int ans = 0;
        int j = 0;
        final var n = nums.length;
        for (var i = 1; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            if (nums[i] > nums[j] && nums[i] > nums[i + 1]) {
                ++ans;
            }
            if (nums[i] < nums[j] && nums[i] < nums[i + 1]) {
                ++ans;
            }
            j = i;
        }
        return ans;
    }
}
