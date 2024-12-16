
import java.util.*;

class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        for (int i = 0; i < nums.length; ++i) {
            var el = new int[]{nums[i], i};
            pq.add(el);
        }
        for (int i = 0; i < k; ++i) {
            var el = pq.poll();
            el[0] *= multiplier;
            nums[el[1]] = el[0];
            pq.add(el);
        }
        return nums;
    }
}
