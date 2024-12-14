
import java.util.*;

class Solution {
    public long continuousSubarrays(int[] nums) {
        var n = nums.length;
        long cnt = 0L;
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        var i = 0;
        for (var j = 0; j < n; ++j) {
            mp.put(nums[j], mp.getOrDefault(nums[j], 0) + 1);
            while (i < j && mp.lastEntry().getKey() - mp.firstEntry().getKey() > 2) {
                mp.put(nums[i], mp.getOrDefault(nums[i], 0) - 1);
                if (mp.get(nums[i]) == 0) {
                    mp.remove(nums[i]);
                }
                ++i;
            }
            cnt += j - i + 1;
        }
        return cnt;
    }
}