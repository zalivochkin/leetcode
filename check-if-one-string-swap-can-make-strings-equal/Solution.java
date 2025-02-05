
import java.util.*;

class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        final var n = s1.length();
        int cnt = 0;
        char ch1 = 0;
        char ch2 = 0;
        for (var i = 0; i < n; ++i) {
            if (s1.charAt(i) != s2.charAt(i)) {
                ++cnt;
                if (cnt > 2 || (cnt == 2 && (s1.charAt(i) != ch2 || s2.charAt(i) != ch1))) {
                    return false;
                }
                ch1 = s1.charAt(i);
                ch2 = s2.charAt(i);
            }
        }
        return cnt != 1;
    }
}
