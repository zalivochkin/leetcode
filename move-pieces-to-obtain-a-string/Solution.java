
public class Solution {
    public boolean canChange(String start, String target) {
        var n = start.length();
        var lft = 0;
        var rght = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            if (start.charAt(i) == 'L') {
                ++lft;
            }
            if (target.charAt(i) == 'L') {
                --lft;
            }
            if (start.charAt(i) == 'R') {
                ++rght;
            }
            if (target.charAt(i) == 'R') {
                --rght;
            }
            if (start.charAt(i) != '_') {
                for (; j < n; ++j) {
                    if (target.charAt(j) != '_') {
                        break;
                    }
                }
                if (j == n || start.charAt(i) != target.charAt(j) || (start.charAt(i) == 'R' && i > j) || (start.charAt(i) == 'L' && i < j)) {
                    return false;
                }
                ++j;
            }
        }
        return lft == 0 && rght == 0;
    }
}
