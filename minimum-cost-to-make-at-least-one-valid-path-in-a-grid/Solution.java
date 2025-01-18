
import java.util.*;

class Solution {
    public int minCost(int[][] grid) {
        var n = grid.length;
        var m = grid[0].length;
        boolean[][] vis = new boolean[n][m];
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {0, 0, 0});
        int[][] dirs = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int i, j, x, y;
        while (!q.isEmpty()) {
            var p = q.poll();
            i = p[0];
            j = p[1];
            if (i == n - 1 && j == m - 1) {
                return p[2];
            }
            if (vis[i][j]) {
                continue;
            }
            vis[i][j] = true;
            for (var k = 1; k <= 4; ++k) {
                x = i + dirs[k][0];
                y = j + dirs[k][1];
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    if (grid[i][j] == k) {
                        q.offerFirst(new int[] {x, y, p[2]});
                    } else {
                        q.offer(new int[] {x, y, p[2] + 1});
                    }
                }
            }
        }
        return -1;
    }
}
