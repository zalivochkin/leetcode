
import java.util.*;

class Solution {
    public String repeatLimitedString(String s, int repeatLimit) {
        Map<Integer, Integer> mp = new HashMap<>();
        for (var c : s.toCharArray()) {
            mp.put(c - 'a', mp.getOrDefault(c - 'a', 0) + 1);
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for (var entry : mp.entrySet()) {
            int ch = entry.getKey();
            pq.add(new int[]{(char) ch + 'a', entry.getValue()});
        }
        StringBuilder ans = new StringBuilder();
        while (!pq.isEmpty()) {
            var current = pq.poll();
            var used = Math.min(repeatLimit, current[1]);
            ans.append(String.valueOf((char)current[0]).repeat(Math.max(0, used)));
            current[1] -= used;
            if (current[1] > 0) {
                if (pq.isEmpty()) {
                    break;
                }
                var next = pq.poll();
                ans.append((char)next[0]);
                --next[1];
                if (next[1] > 0) {
                    pq.add(next);
                }
                pq.add(current);
            }
        }
        return ans.toString();
    }
}
