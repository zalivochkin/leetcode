
import java.util.*;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> mp = new HashMap<>();
        for (var i = 0; i < nums.length; ++i) {
            if (mp.isEmpty()) {
                mp.put(nums[i], i);
            } else {
                if (mp.containsKey(target - nums[i])) {
                    return new int[]{mp.get(target - nums[i]), i};
                }
                mp.put(nums[i], i);
            }
        }
        return new int[]{-1, -1};
    }
}
