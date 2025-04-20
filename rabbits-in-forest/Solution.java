
import java.util.*;

class Solution {
    public int numRabbits(int[] answers) {
        Map<Integer, Integer> counter = new HashMap<>();
        for (var cnt : answers) {
            counter.put(cnt, counter.getOrDefault(cnt, 0) + 1);
        }
        int res = 0;
        for (var entry : counter.entrySet()) {
            int answer = entry.getKey();
            int count = entry.getValue();
            res += (int) Math.ceil(count / (double) (answer + 1)) * (answer + 1);
        }
        return res;
    }
}
