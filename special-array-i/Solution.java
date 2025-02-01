
import java.util.*;

class Solution {
    public boolean isArraySpecial(int[] nums) {
        final var n = nums.length;
        for (var i = 1; i < n; ++i) {
            if (nums[i - 1] % 2 == 0 && nums[i] % 2 == 0) {
                return false;
            }
            if (nums[i - 1] % 2 != 0 && nums[i] % 2 != 0) {
                return false;
            }
        }
        return true;
    }
}
