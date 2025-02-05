
import java.util.*;

class Solution {
    public int maxAscendingSum(int[] nums) {
        final var n = nums.length;
        int currSum = nums[0];
        int maxSum = currSum;
        for (var i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                currSum += nums[i];
                maxSum = Math.max(maxSum, currSum);
            } else {
                currSum = nums[i];
            }
        }
        return maxSum;
    }
}
