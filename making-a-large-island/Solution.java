
import java.util.*;

class Solution {
    public final int[] dirs = {-1, 0, 1, 0, -1};
    public int dfs(int[][] grid, int[][] p, int root, int[] cnts, int i, int j) {
        final var n = grid.length;
        p[i][j] = root;
        ++cnts[root];
        for (var k = 0; k < 4; ++k) {
            int ki = i + dirs[k];
            int kj = j + dirs[k + 1];
            if (ki >= 0 && ki < n && kj >= 0 && kj < n && grid[ki][kj] == 1 && p[ki][kj] == 0) {
                dfs(grid, p, root, cnts, ki, kj);
            }
        }
        return cnts[root];
    }

    public int largestIsland(int[][] grid) {
        final var n = grid.length;
        int[][] p = new int[n][n];
        int[] cnts = new int[n * n + 1];
        int root = 0;
        int res = 0;
        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && p[i][j] == 0) {
                    ++root;
                    res = Math.max(res, dfs(grid, p, root, cnts, i, j));
                }
            }
        }
        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    Set<Integer> s = new HashSet<>();
                    for (var k = 0; k < 4; ++k) {
                        int ki = i + dirs[k];
                        int kj = j + dirs[k + 1];
                        if (ki >= 0 && ki < n && kj >= 0 && kj < n) {
                            s.add(p[ki][kj]);
                        }
                    }
                    int cnt = 1;
                    for (var x : s) {
                        cnt += cnts[x];
                    }
                    res = Math.max(res, cnt);
                }
            }
        }
        return res;
    }
}
