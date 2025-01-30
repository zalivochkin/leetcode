
import java.util.*;

class Solution {
    public int maxSubArray(int[] nums) {
        int res = nums[0];
        var dp = nums[0];
        for (var i = 1; i < nums.length; ++i) {
            dp = Math.max(dp, 0) + nums[i];
            res = Math.max(res, dp);
        }
        return res;
    }
}
