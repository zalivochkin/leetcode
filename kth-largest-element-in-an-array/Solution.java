
import java.util.*;

class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(nums.length, Collections.reverseOrder());
        for (var num : nums) {
            pq.add(num);
        }
        for (var i = 1; i < k; ++i) {
            pq.poll();
        }
        return pq.peek();
    }
}
