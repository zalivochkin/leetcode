
import java.util.*;

class Solution {
    public int countServers(int[][] grid) {
        var n = grid.length;
        var m = grid[0].length;
        var row = new int[n];
        var col = new int[m];
        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    row[i] += 1;
                    col[j] += 1;
                }
            }
        }
        int res = 0;
        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1)) {
                    ++res;
                }
            }
        }
        return res;
    }
}
