
import java.util.*;

class Solution {
    public boolean canBeValid(String s, String locked) {
        final var n = s.length();
        if (n % 2 == 1) {
            return false;
        }
        int cntr = 0;
        for (var i = 0; i < n; ++i) {
            if (s.charAt(i) == '(' || locked.charAt(i) == '0') {
                ++cntr;
            } else if (cntr > 0) {
                --cntr;
            } else {
                return false;
            }
        }
        cntr = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s.charAt(i) == ')' || locked.charAt(i) == '0') {
                ++cntr;
            } else if (cntr > 0) {
                --cntr;
            } else {
                return false;
            }
        }
        return true;
    }
}
