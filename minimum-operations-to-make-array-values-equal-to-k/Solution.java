
import java.util.*;

class Solution {
    public int minOperations(int[] nums, int k) {
        Set<Integer> hasX = new HashSet<>();
        int xMin = Integer.MAX_VALUE;
        for (int x: nums) {
            hasX.add(x);
            xMin = Math.min(x, xMin);
        }
        if (xMin < k) {
            return -1;
        }
        return (xMin == k) ? hasX.size() - 1 : hasX.size();
    }
}
