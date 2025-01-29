
import java.util.*;

class Solution {
    public int find(int[] p, int x) {
        if (p[x] != x) {
            p[x] = find(p, p[x]);
        }
        return p[x];
    }
    public int[] findRedundantConnection(int[][] edges) {
        final var n = edges.length;
        var p = new int[n];
        for (var i = 0; i < n; ++i) {
            p[i] = i;
        }
        int pa, pb;
        for (var i = 0;; ++i) {
            pa = find(p, edges[i][0] - 1);
            pb = find(p, edges[i][1] - 1);
            if (pa == pb) {
                return edges[i];
            }
            p[pa] = pb;
        }
    }
}
