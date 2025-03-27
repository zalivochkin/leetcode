
import java.util.*;

class Solution {
    public int minimumIndex(List<Integer> nums) {
        int x = 0;
        int cnt = 0;
        Map<Integer, Integer> freq = new HashMap<>();
        for (var num : nums) {
            freq.merge(num, 1, Integer::sum);
            if (freq.get(num) > cnt) {
                cnt = freq.get(num);
                x = num;
            }
        }
        int cur = 0;
        final var n = nums.size();
        for (var i = 1; i <= n; ++i) {
            if (nums.get(i - 1) == x) {
                ++cur;
                if (cur * 2 > i && (cnt - cur) * 2 > nums.size() - i) {
                    return i - 1;
                }
            }
        }
        return -1;
    }
}
