
import java.util.*;

class Solution {
    public int removeDuplicates(int[] nums) {
        final var n = nums.length;
        int i = Math.min(2, n);
        for (var j = 2; j < n; j++) {
            if (nums[j] != nums[i - 2]) {
                nums[i] = nums[j];
                ++i;
            }
        }
        return i;
    }
}
