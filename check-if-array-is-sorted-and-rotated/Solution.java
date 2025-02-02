
import java.util.*;

class Solution {
    public boolean check(int[] nums) {
        final var n = nums.length;
        int cnt = 0;
        for (var i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                ++cnt;
                if (cnt > 1) {
                    break;
                }
            }
        }
        return cnt == 0 || cnt == 1 && nums[0] >= nums[n - 1];
    }
}
