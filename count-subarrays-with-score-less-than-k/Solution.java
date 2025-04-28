
class Solution {
    public long countSubarrays(int[] nums, long k) {
        long ans = 0;
        long s = 0;
        final var n = nums.length;
        for (int i = 0, j = 0; i < n; ++i) {
            s += nums[i];
            while (s * (i - j + 1) >= k) {
                s -= nums[j];
                ++j;
            }
            ans += i - j + 1;
        }
        return ans;
    }
}
