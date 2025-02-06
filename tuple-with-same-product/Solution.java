
import java.util.*;

class Solution {
    public int tupleSameProduct(int[] nums) {
        Map<Integer, Integer> cnts = new HashMap<>();
        for (var i = 1; i < nums.length; ++i) {
            for (var j = 0; j < i; ++j) {
                cnts.merge(nums[i] * nums[j], 1, Integer::sum);
            }
        }
        int ans = 0;
        for (int cnt : cnts.values()) {
            ans += cnt * (cnt - 1) / 2;
        }
        return ans << 3;
    }
}
