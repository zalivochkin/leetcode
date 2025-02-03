
import java.util.*;

class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        final var n = nums.length;
        int ans = 1;
        for (int i = 1, t = 1; i < n; ++i) {
            if (nums[i - 1] < nums[i]) {
                ans = Math.max(ans, ++t);
            } else {
                t = 1;
            }
        }
        for (int i = 1, t = 1; i < n; ++i) {
            if (nums[i - 1] > nums[i]) {
                ans = Math.max(ans, ++t);
            } else {
                t = 1;
            }
        }
        return ans;
    }
}
