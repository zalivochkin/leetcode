
import java.util.*;

class Solution {
    int[][] dirs= {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int dfs(int[][] grid, boolean[][] visited, int i, int j) {
        final var n = grid.length;
        final var m = grid[0].length;
        final var l = dirs.length;
        int res = grid[i][j];
        visited[i][j] = true;
        for (var k = 0; k < l; ++k) {
            int ki = i + dirs[k][0];
            int kj = j + dirs[k][1];
            if (ki >= 0 && ki < n && kj >= 0 && kj < m && grid[ki][kj] > 0 && !visited[ki][kj]) {
                res += dfs(grid, visited, ki, kj);
            }
        }
        return res;
    }
    public int findMaxFish(int[][] grid) {
        final var n = grid.length;
        final var m = grid[0].length;
        int res = 0;
        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < m; ++j) {
                if (grid[i][j] > 0) {
                    boolean[][] visited = new boolean[n][m];
                    res = Math.max(res, dfs(grid, visited, i, j));
                }
            }
        }
        return res;
    }
}
