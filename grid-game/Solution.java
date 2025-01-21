
import java.util.*;

class Solution {
    public long gridGame(int[][] grid) {
        var n = grid[0].length;
        long s1 = 0L;
        for (var pts : grid[0]) {
            s1 += pts;
        }
        long s2 = 0L;
        long res = Long.MAX_VALUE;
        for (var i = 0; i < n; ++i) {
            s1 -= grid[0][i];
            res = Math.min(res, Math.max(s1, s2));
            s2 += grid[1][i];
        }
        return res;
    }
}
