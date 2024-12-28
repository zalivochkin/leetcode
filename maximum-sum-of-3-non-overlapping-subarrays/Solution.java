
import java.util.*;

class Solution {
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int[] res = new int[]{0, 0, 0};
        int[] sums = new int[]{0, 0, 0, 0};
        int[] maxs = new int[]{0, 0};
        int[] idxex = new int[]{0, 0, 0};
        Arrays.fill(idxex, 0);
        for (var i = k * 2; i < nums.length; ++i) {
            sums[1] += nums[i - k * 2];
            sums[2] += nums[i - k];
            sums[3] += nums[i];
            if (i >= k * 3 - 1) {
                if (sums[1] > maxs[0]) {
                    maxs[0] = sums[1];
                    idxex[0] = i - k * 3 + 1;
                }
                if (maxs[0] + sums[2] > maxs[1]) {
                    maxs[1] = maxs[0] + sums[2];
                    idxex[1] = idxex[0];
                    idxex[2] = i - k * 2 + 1;
                }
                if (maxs[1] + sums[3] > sums[0]) {
                    sums[0] = maxs[1] + sums[3];
                    res[0] = idxex[1];
                    res[1] = idxex[2];
                    res[2] = i - k + 1;
                }
                sums[1] -= nums[i - k * 3 + 1];
                sums[2] -= nums[i - k * 2 + 1];
                sums[3] -= nums[i - k + 1];
            }
        }
        return res;
    }
}
