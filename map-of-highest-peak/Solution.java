
import java.util.*;

class Solution {
    public int[][] highestPeak(int[][] isWater) {
        final var n = isWater.length;
        final var m = isWater[0].length;
        int[][] res = new int[n][m];
        Deque<int[]> dq = new ArrayDeque<>();
        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < m; ++j) {
                res[i][j] = isWater[i][j] - 1;
                if (res[i][j] == 0) {
                    dq.offer(new int[] {i, j});
                }
            }
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        int i, j;
        while (!dq.isEmpty()) {
            var p = dq.poll();
            for (int k = 0; k < 4; ++k) {
                i = p[0] + dirs[k];
                j = p[1] + dirs[k + 1];
                if (i >= 0 && i < n && j >= 0 && j < m && res[i][j] == -1) {
                    res[i][j] = res[p[0]][p[1]] + 1;
                    dq.offer(new int[] {i, j});
                }
            }
        }
        return res;
    }
}
