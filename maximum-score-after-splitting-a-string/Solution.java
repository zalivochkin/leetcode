
import java.util.*;

class Solution {
    public int maxScore(String s) {
        var lft = 0;
        var rght = 0;
        for (var i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '1') {
                ++rght;
            }
        }
        var ans = 0;
        for (var i = 0; i < s.length() - 1; ++i) {
            lft += (s.charAt(i) - '0') ^ 1;
            rght -= s.charAt(i) - '0';
            ans = Math.max(ans, lft + rght);
        }
        return ans;
    }
}
