
import java.util.*;

class Solution {
    public int[] applyOperations(int[] nums) {
        final var n = nums.length;
        for (var i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] <<= 1;
                nums[i + 1] = 0;
            }
        }
        int[] ans = new int[n];
        int i = 0;
        for (var num : nums) {
            if (num > 0) {
                ans[i] = num;
                ++i;
            }
        }
        return ans;
    }
}
