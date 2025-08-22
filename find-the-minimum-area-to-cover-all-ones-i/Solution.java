
class Solution {
    public int minimumArea(int[][] grid) {
        final var n = grid.length;
        final var m = grid[0].length;
        int x1 = n;
        int y1 = m;
        int x2 = 0;
        int y2 = 0;
        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    x1 = Math.min(x1, i);
                    y1 = Math.min(y1, j);
                    x2 = Math.max(x2, i);
                    y2 = Math.max(y2, j);
                }
            }
        }
        return (x2 - x1 + 1) * (y2 - y1 + 1);
    }
}
