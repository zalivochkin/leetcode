
import java.util.*;

class Solution {
    public long putMarbles(int[] weights, int k) {
        final var n = weights.length;
        int[] scores = new int[n - 1];
        for (var i = 0; i < n - 1; ++i) {
            scores[i] = weights[i] + weights[i + 1];
        }
        Arrays.sort(scores);
        long ans = 0;
        for (var i = 0; i < k - 1; ++i) {
            ans -= scores[i];
            ans += scores[n - 2 - i];
        }
        return ans;
    }
}
