
import java.util.*;

class Solution {
    public boolean check(String s, int i, int x) {
        final var n = s.length();
        if (i >= n) {
            return x == 0;
        }
        int y = 0;
        for (var j = i; j < n; ++j) {
            y = y * 10 + s.charAt(j) - '0';
            if (y > x) {
                break;
            }
            if (check(s, j + 1, x - y)) {
                return true;
            }
        }
        return false;
    }

    public int punishmentNumber(int n) {
        int ans = 0;
        for (var i = 1; i <= n; ++i) {
            int x = i * i;
            if (check(x + "", 0, i)) {
                ans += x;
            }
        }
        return ans;
    }
}
