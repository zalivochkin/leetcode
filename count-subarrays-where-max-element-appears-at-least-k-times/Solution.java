
import java.util.*;

class Solution {
    public long countSubarrays(int[] nums, int k) {
        int mx = Arrays.stream(nums).max().getAsInt();
        final var n = nums.length;
        long ans = 0;
        int cnt = 0;
        int j = 0;
        for (var num : nums) {
            while (j < n && cnt < k) {
                if (nums[j] == mx) {
                    ++cnt;
                }
                ++j;
            }
            if (cnt < k) {
                break;
            }
            ans += n - j + 1;
            if (num == mx) {
                --cnt;
            }
        }
        return ans;
    }
}
