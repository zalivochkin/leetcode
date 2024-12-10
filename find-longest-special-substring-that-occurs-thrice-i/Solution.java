import java.util.*;

public class Solution {
    public int maximumLength(String s) {
        var n = s.length();
        int res = -1;
        Map<String, Integer> freq = new HashMap<>();
        for (var len = 1; len <= n; ++len) {
            freq.clear();
            for (var i = 0; i <= n - len; ++i) {
                String sub = s.substring(i, i + len);
                boolean is_special = true;
                for (int j = 1; j < len; ++j) {
                    if (sub.charAt(j) != sub.charAt(0)) {
                        is_special = false;
                        break;
                    }
                }
                if (is_special) {
                    freq.put(sub, freq.getOrDefault(sub, 0) + 1);
                    if (freq.get(sub) >= 3) {
                        res = Math.max(res, len);
                    }
                }
            }
        }
        return res;
    }
}
