
import java.util.*;

class Solution {
    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        final var n = nums.length;
        var idx = new Integer[n];
        for (var i = 0; i < n; ++i) {
            idx[i] = i;
        }
        Arrays.sort(idx, Comparator.comparingInt(i -> nums[i]));
        var res = new int[n];
        int i = 0, j;
        while (i < n) {
            j = i + 1;
            while (j < n && nums[idx[j]] - nums[idx[j - 1]] <= limit) {
                ++j;
            }
            var tmp = Arrays.copyOfRange(idx, i, j);
            Arrays.sort(tmp);
            for (var k = i; k < j; ++k) {
                res[tmp[k - i]] = nums[idx[k]];
            }
            i = j;
        }
        return res;
    }
}
