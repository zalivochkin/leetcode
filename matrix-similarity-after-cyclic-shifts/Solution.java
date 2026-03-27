
class Solution {
    public boolean areSimilar(int[][] mat, int k) {
        final var n = mat.length;
        final var m = mat[0].length;
        k %= m;
        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < m; ++j) {
                if (i % 2 == 1 && mat[i][j] != mat[i][(j + k) % m]) {
                    return false;
                }
                if (i % 2 == 0 && mat[i][j] != mat[i][(j - k + m) % m]) {
                    return false;
                }
            }
        }
        return true;
    }
}
