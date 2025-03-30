
import java.util.*;

class Solution {
    public List<Integer> partitionLabels(String s) {
        Map<Character, Integer> last = new HashMap<>();
        final var n = s.length();
        for (var i = 0; i < n; ++i) {
            last.put(s.charAt(i), i);
        }
        List<Integer> ans = new ArrayList<>();
        int mx = 0;
        int end = 0;
        for (var start = 0; start < n; ++start) {
            mx = Math.max(mx, last.get(s.charAt(start)));
            if (mx == start) {
                ans.add(start - end + 1);
                end = start + 1;
            }
        }
        return ans;
    }
}
