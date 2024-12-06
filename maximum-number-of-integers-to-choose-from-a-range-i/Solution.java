import java.util.Set;

public class Solution {
    public int maxCount(int[] banned, int n, int maxSum) {
        Set<Integer> banned_s = new HashSet<Integer>();
        for (var b : banned) {
            if (b <= maxSum) {
                banned_s.add(b);
            }
        }
        var cur_sum = 0L;
        int res = 0;
        for (var i = 1; i <= n; ++i) {
            if (banned_s.contains(i)) {
                continue;
            }
            cur_sum += i;
            if (cur_sum > maxSum) {
                break;
            }
            ++res;
        }
        return res;
    }
}
