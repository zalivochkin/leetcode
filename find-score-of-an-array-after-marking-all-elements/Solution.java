import java.util.Objects;
import java.util.PriorityQueue;

class Solution {
    static class Element {
        public Element(Integer index_, Integer score_) {
            index = index_;
            score = score_;
        }
        public Integer index;
        public Integer score;
    }
    public long findScore(int[] nums) {
        long score = 0;
        PriorityQueue<Element> pq = new PriorityQueue<>((e1, e2) -> {
            if (!Objects.equals(e1.score, e2.score)) {
                return Integer.compare(e1.score, e2.score);
            }
            return Integer.compare(e1.index, e2.index);
        });
        var i = 0;
        boolean[] marked = new boolean[nums.length + 2];
        for (var num : nums) {
            pq.add(new Element(i, num));
            marked[i] = false;
            ++i;
        }
        while (!pq.isEmpty()) {
            var el = pq.poll();
            if (!marked[el.index + 1]) {
                score += el.score;
                marked[el.index] = true;
                marked[el.index + 1] = true;
                marked[el.index + 2] = true;
            }
        }
        return score;
    }
}
