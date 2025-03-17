
import java.util.*;

class Solution {
    public boolean divideArray(int[] nums) {
        final var n = nums.length;
        Arrays.sort(nums);
        for (var i = 1; i < n; i += 2) {
            if (nums[i] != nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
}
