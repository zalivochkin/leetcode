
import java.util.*;

class Solution {
    public char[][] grid;
    public int m;
    public int n;
    public void dfs(int i, int j) {
        grid[i][j] = '0';
        int[] dirs = {-1, 0, 1, 0, -1};
        for (var k = 0; k < 4; ++k) {
            int ki = i + dirs[k];
            int kj = j + dirs[k + 1];
            if (ki >= 0 && ki < m && kj >= 0 && kj < n && grid[ki][kj] == '1') {
                dfs(ki, kj);
            }
        }
    }

    public int numIslands(char[][] grid) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        int ans = 0;
        for (var i = 0; i < m; ++i) {
            for (var j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    dfs(i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }
}
