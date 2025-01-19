
import java.util.*;

class Solution {
    public int trapRainWater(int[][] heightMap) {
        var n = heightMap.length;
        var m = heightMap[0].length;
        var visited = new boolean[n][m];
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < m; ++j) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    pq.offer(new int[] {heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
            }
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        int x, y;
        int res = 0;
        while (!pq.isEmpty()) {
            var p = pq.poll();
            for (var k = 0; k < 4; ++k) {
                x = p[1] + dirs[k];
                y = p[2] + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]) {
                    visited[x][y] = true;
                    res += Math.max(0, p[0] - heightMap[x][y]);
                    pq.offer(new int[] {Math.max(p[0], heightMap[x][y]), x, y});
                }
            }
        }
        return res;
    }
}
