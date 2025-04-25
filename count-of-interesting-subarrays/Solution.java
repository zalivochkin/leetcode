
import java.util.*;

class Solution {
    public long countInterestingSubarrays(List<Integer> nums, int modulo, int k) {
        final var n = nums.size();
        List<Boolean> isGood = new ArrayList<>(n);
        for (var num : nums) {
            isGood.add(num % modulo == k);
        }
        Map<Integer, Integer> cnts = new HashMap<>();
        cnts.put(0, 1);
        long ans = 0;
        int s = 0;
        for (var x : isGood) {
            if (x) {
                s += 1;
            }
            ans += cnts.getOrDefault((s - k + modulo) % modulo, 0);
            cnts.merge(s % modulo, 1, Integer::sum);
        }
        return ans;
    }
}
