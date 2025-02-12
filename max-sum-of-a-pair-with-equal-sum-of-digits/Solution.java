
import java.util.*;

class Solution {
    public int maximumSum(int[] nums) {
        int[] sums = new int[100];
        int ans = -1;
        for (var num : nums) {
            int sum = 0;
            for (var y = num; y > 0; y /= 10) {
                sum += y % 10;
            }
            if (sums[sum] > 0) {
                ans = Math.max(ans, sums[sum] + num);
            }
            sums[sum] = Math.max(sums[sum], num);
        }
        return ans;
    }
}
