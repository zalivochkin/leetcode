
import java.util.*;

class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        final var n = A.length;
        var vis = new int[n + 1];
        Arrays.fill(vis, 1);
        int summ = 0;
        var res = new int[n];
        for (var i = 0; i < n; ++i) {
            vis[A[i]] ^= 1;
            summ += vis[A[i]];
            vis[B[i]] ^= 1;
            summ += vis[B[i]];
            res[i] = summ;
        }
        return res;
    }
}
