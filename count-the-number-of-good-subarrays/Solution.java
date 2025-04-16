
import java.util.*;

class Solution {
    public long countGood(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        long ans = 0;
        long cur = 0;
        int i = 0;
        for (var num : nums) {
            cur += cnt.getOrDefault(num, 0);
            cnt.merge(num, 1, Integer::sum);
            while (cur - cnt.get(nums[i]) + 1 >= k) {
                cnt.merge(nums[i], -1, Integer::sum);
                cur -= cnt.get(nums[i]);
                ++i;
            }
            if (cur >= k) {
                ans += i + 1;
            }
        }
        return ans;
    }
}
