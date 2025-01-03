
import java.util.*;

class Solution {
    public int waysToSplitArray(int[] nums) {
        var totalSum = 0L;
        for (var num : nums) {
            totalSum += num;
        }
        var curSum = 0L;
        int res = 0;
        for (var i = 0; i + 1 < nums.length; ++i) {
            curSum += nums[i];
            if (curSum >= totalSum - curSum) {
                ++res;
            }
        }
        return res;
    }
}
