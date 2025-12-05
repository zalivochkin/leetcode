
class Solution {
    public int countPartitions(int[] nums) {
        int left_sum = nums[0];
        int right_sum = 0;
        final var n = nums.length;
        for (int i = 1; i < n; ++i) {
            right_sum += nums[i];
        }
        int ans = 0;
        if (((left_sum - right_sum) % 2) == 0) {
            ++ans;
        }
        for (int i = 1; i < n - 1; ++i) {
            left_sum += nums[i];
            right_sum -= nums[i];
            if (((left_sum - right_sum) % 2) == 0) {
                ++ans;
            }
        }
        return ans;
    }
}
