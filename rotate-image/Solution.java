
import java.util.*;

class Solution {
    public void rotate(int[][] matrix) {
        final var n = matrix.length;
        for (var i = 0; i < n / 2; ++i) {
            for (var j = 0; j < n; ++j) {
                final var tmp = matrix[i][j];
                matrix[i][j] = matrix[n - i - 1][j];
                matrix[n - i - 1][j] = tmp;
            }
        }
        for (var i = 0; i < n; ++i) {
            for (var j = 0; j <= i; ++j) {
                final var tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
}
