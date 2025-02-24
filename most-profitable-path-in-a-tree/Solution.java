
import java.util.*;

class Solution {
    public List<Integer>[] graph;
    public int[] amount;
    public int[] ts;
    public int ans = Integer.MIN_VALUE;

    public boolean dfs1(int i, int fa, int t) {
        if (i == 0) {
            ts[i] = Math.min(ts[i], t);
            return true;
        }
        for (var j : graph[i]) {
            if (j != fa && dfs1(j, i, t + 1)) {
                ts[j] = Math.min(ts[j], t + 1);
                return true;
            }
        }
        return false;
    }

    public void dfs2(int i, int fa, int t, int v) {
        if (t == ts[i]) {
            v += amount[i] >> 1;
        } else if (t < ts[i]) {
            v += amount[i];
        }
        if (graph[i].size() == 1 && graph[i].get(0) == fa) {
            ans = Math.max(ans, v);
            return;
        }
        for (var j : graph[i]) {
            if (j != fa) {
                dfs2(j, i, t + 1, v);
            }
        }
    }

    public int mostProfitablePath(int[][] edges, int bob, int[] amount) {
        final var n = edges.length + 1;
        graph = new List[n];
        ts = new int[n];
        this.amount = amount;
        Arrays.setAll(graph, k -> new ArrayList<>());
        Arrays.fill(ts, n);
        for (var edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            graph[node1].add(node2);
            graph[node2].add(node1);
        }
        dfs1(bob, -1, 0);
        ts[bob] = 0;
        dfs2(0, -1, 0, 0);
        return ans;
    }
}
