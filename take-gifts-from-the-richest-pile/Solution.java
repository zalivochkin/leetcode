import java.util.*;

class Solution {
    public long pickGifts(int[] gifts, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        long total_gifts = 0L;
        for (var gift : gifts) {
            pq.add(gift);
            total_gifts += gift;
        }
        for (var i = 0; i < k; ++i) {
            var gift = pq.poll();
            var new_gift = (int) Math.floor(Math.sqrt(gift));
            pq.add(new_gift);
            total_gifts -= gift - new_gift;
        }
        return total_gifts;
    }
}
