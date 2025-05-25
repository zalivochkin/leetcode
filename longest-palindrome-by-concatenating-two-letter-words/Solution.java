
import java.util.*;

class Solution {
    public int longestPalindrome(String[] words) {
        Map<String, Integer> cnt = new HashMap<>();
        for (final var word : words) {
            cnt.put(word, cnt.getOrDefault(word, 0) + 1);
        }
        int ans = 0;
        int x = 0;
        for (final var entry : cnt.entrySet()) {
            final var k = entry.getKey();
            final var rk = new StringBuilder(k).reverse().toString();
            int v = entry.getValue();
            if (k.charAt(0) == k.charAt(1)) {
                x += v & 1;
                ans += v / 2 * 2 * 2;
            } else {
                ans += Math.min(v, cnt.getOrDefault(rk, 0)) * 2;
            }
        }
        ans += x > 0 ? 2 : 0;
        return ans;
    }
}
