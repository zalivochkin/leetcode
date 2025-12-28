
class Solution {
    public int countNegatives(int[][] grid) {
        final var n = grid.length;
        final var m = grid[0].length;
        int ans = 0;
        int i = n - 1;
        int j = 0;
        while (i >= 0 && j < m) {
            if (grid[i][j] < 0) {
                ans += m - j;
                --i;
            } else {
                ++j;
            }
        }
        return ans;
    }
}
