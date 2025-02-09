
import java.util.*;

class Solution {
    public long countBadPairs(int[] nums) {
        Map<Integer, Integer> cnts = new HashMap<>();
        long cnt = 0;
        for (var i = 0; i < nums.length; ++i) {
            cnt += i - cnts.getOrDefault(i - nums[i], 0);
            cnts.merge(i - nums[i], 1, Integer::sum);
        }
        return cnt;
    }
}
