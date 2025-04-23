
import java.util.*;

class Solution {
    public int countLargestGroup(int n) {
        Map<Integer, Integer> cnts = new HashMap<>();
        int ans = 0;
        int mx = 0;
        int s;
        for (var i = 1; i <= n; ++i) {
            s = 0;
            for (var x = i; x > 0; x /= 10) {
                s += x % 10;
            }
            cnts.merge(s, 1, Integer::sum);
            if (mx < cnts.get(s)) {
                mx = cnts.get(s);
                ans = 1;
            } else if (mx == cnts.get(s)) {
                ++ans;
            }
        }
        return ans;
    }
}
