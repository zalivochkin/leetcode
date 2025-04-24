
import java.util.*;

class Solution {
    public int countCompleteSubarrays(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for (var x : nums) {
            s.add(x);
        }
        final var cnt = s.size();
        int ans = 0;
        final var n = nums.length;
        for (var i = 0; i < n; ++i) {
            s.clear();
            for (var j = i; j < n; ++j) {
                s.add(nums[j]);
                if (s.size() == cnt) {
                    ++ans;
                }
            }
        }
        return ans;
    }
}
