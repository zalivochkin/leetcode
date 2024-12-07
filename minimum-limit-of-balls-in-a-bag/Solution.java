import java.util.*;

public class Solution {
    public int minimumSize(int[] nums, int maxOperations) {
        var left = 1;
        var right = Arrays.stream(nums).max().orElse(left);
        var mid = left;
        int cnt;
        while (left < right) {
            mid = left + (right - left) / 2;
//            int final_mid = mid;
//            cnt = Arrays.stream(nums).reduce(0, (cur_sum, num) -> cur_sum + (num - 1) / final_mid);
            cnt = 0;
            for (var i : nums) {
                cnt += (i - 1) / mid;
            }
            if (cnt <= maxOperations) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
