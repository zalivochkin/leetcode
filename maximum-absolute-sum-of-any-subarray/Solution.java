
import java.util.*;

class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int max_sum = 0;
        int min_sum = 0;
        int res = 0;
        for (var num : nums) {
            max_sum = Math.max(max_sum, 0) + num;
            min_sum = Math.min(min_sum, 0) + num;
            res = Math.max(res, Math.max(max_sum, Math.abs(min_sum)));
        }
        return res;
    }
}
