
import java.util.*;

class Solution {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        var n = mat.length;
        var m = mat[0].length;
        Map<Integer, int[]> idxs = new HashMap<>();
        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < m; ++j) {
                idxs.put(mat[i][j], new int[] {i, j});
            }
        }
        var row = new int[n];
        var col = new int[m];
        int k = 0;
        while (true) {
            var idx = idxs.get(arr[k]);
            row[idx[0]] += 1;
            col[idx[1]] += 1;
            if (row[idx[0]] == m || col[idx[1]] == n) {
                return k;
            }
            ++k;
        }
    }
}
