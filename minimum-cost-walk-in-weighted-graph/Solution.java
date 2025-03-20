
import java.util.*;

class Solution {
    class UnionFind {
        private final int[] p;
        private final int[] size;

        public UnionFind(int n) {
            p = new int[n];
            size = new int[n];
            for (var i = 0; i < n; ++i) {
                p[i] = i;
                size[i] = 1;
            }
        }

        public int find(int x) {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        }

        public boolean union(int a, int b) {
            final var pa = find(a);
            final var pb = find(b);
            if (pa == pb) {
                return false;
            }
            if (size[pa] > size[pb]) {
                p[pb] = pa;
                size[pa] += size[pb];
            } else {
                p[pa] = pb;
                size[pb] += size[pa];
            }
            return true;
        }

        public int size(int x) {
            return size[find(x)];
        }
    }

    public int f(UnionFind uf, int[] g, int u, int v) {
        if (u == v) {
            return 0;
        }
        final var a = uf.find(u);
        final var b = uf.find(v);
        return a == b ? g[a] : -1;
    }

    public int[] minimumCost(int n, int[][] edges, int[][] query) {
        final var m = query.length;
        UnionFind uf = new UnionFind(n);
        int[] g = new int[n];
        for (final var edge : edges) {
            uf.union(edge[0], edge[1]);
        }
        Arrays.fill(g, -1);
        for (final var edge : edges) {
            int root = uf.find(edge[0]);
            g[root] &= edge[2];
        }
        int[] ans = new int[m];
        for (var i = 0; i < m; ++i) {
            ans[i] = f(uf, g, query[i][0], query[i][1]);
        }
        return ans;
    }
}
