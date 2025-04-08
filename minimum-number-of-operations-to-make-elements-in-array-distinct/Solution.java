
import java.util.*;

class Solution {
    public int minimumOperations(int[] nums) {
        Map<Integer, Boolean> visited = new HashMap<>();
        int ans = 0;
        final var n = nums.length;
        for (int i = n - 1; i >= 0; --i) {
            if (visited.getOrDefault(nums[i], Boolean.FALSE)) {
                ans = (int) Math.ceil((double) (i + 1) / 3.0);
                break;
            }
            visited.put(nums[i], Boolean.TRUE);
        }
        return ans;
    }
}
