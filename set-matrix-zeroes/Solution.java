
class Solution {
    public void setZeroes(int[][] matrix) {
        final var n = matrix.length;
        final var m = matrix[0].length;
        boolean[] rows = new boolean[n];
        boolean[] cols = new boolean[m];
        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }
        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < m; ++j) {
                if (rows[i] || cols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}
