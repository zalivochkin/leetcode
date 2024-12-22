
import java.util.*;

class Solution {
    class BinaryIndexedTree {
        private final int inf = 1 << 30;
        private final int n;
        private final int[] c;

        public BinaryIndexedTree(int n) {
            this.n = n;
            c = new int[n + 1];
            Arrays.fill(c, inf);
        }

        public void update(int x, int v) {
            while (x <= n) {
                c[x] = Math.min(c[x], v);
                x += x & -x;
            }
        }

        public int query(int x) {
            int mi = inf;
            while (x > 0) {
                mi = Math.min(mi, c[x]);
                x -= x & -x;
            }
            return mi == inf ? -1 : mi;
        }
    }
    public int[] leftmostBuildingQueries(int[] heights, int[][] queries) {
        var n = heights.length;
        var m = queries.length;
        for (var i = 0; i < m; ++i) {
            if (queries[i][0] > queries[i][1]) {
                queries[i] = new int[] {queries[i][1], queries[i][0]};
            }
        }
        Integer[] idx = new Integer[m];
        for (var i = 0; i < m; ++i) {
            idx[i] = i;
        }
        Arrays.sort(idx, (i, j) -> queries[j][1] - queries[i][1]);
        var s = heights.clone();
        Arrays.sort(s);
        var ans = new int[m];
        var j = n - 1;
        BinaryIndexedTree tree = new BinaryIndexedTree(n);
        for (var i : idx) {
            var l = queries[i][0];
            var r = queries[i][1];
            while (j > r) {
                var k = n - Arrays.binarySearch(s, heights[j]) + 1;
                tree.update(k, j);
                --j;
            }
            if (l == r || heights[l] < heights[r]) {
                ans[i] = r;
            } else {
                var k = n - Arrays.binarySearch(s, heights[l]);
                ans[i] = tree.query(k);
            }
        }
        return ans;
    }
}
