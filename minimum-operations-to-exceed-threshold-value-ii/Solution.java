
import java.util.*;

class Solution {
    public int minOperations(int[] nums, int k) {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        for (var num : nums) {
            pq.offer((long) num);
        }
        int ops = 0;
        while (pq.size() > 1 && pq.peek() < k) {
            long x = pq.poll();
            long y = pq.poll();
            pq.offer(Math.min(x, y) * 2 + Math.max(x, y));
            ++ops;
        }
        return ops;
    }
}
