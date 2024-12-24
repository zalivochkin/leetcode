
import java.util.*;

class Solution {
    private List<Integer>[] g;
    private int ans;
    private int a;
    public int treeDiameter(/*List<Integer>[] g, Integer ans, Integer a, */int[][] edges) {
        int n = edges.length + 1;
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        ans = 0;
        a = 0;
        for (var e : edges) {
            g[e[0]].add(e[1]);
            g[e[1]].add(e[0]);
        }
        dfs(/*g, ans, a, */0, -1, 0);
        dfs(/*g, ans, a, */a, -1, 0);
        return ans;
    }

    private void dfs(/*List<Integer>[] g, Integer ans, Integer a, */int i, int fa, int t) {
        for (int j : g[i]) {
            if (j != fa) {
                dfs(/*g, ans, a, */j, i, t + 1);
            }
        }
        if (ans < t) {
            ans = t;
            a = i;
        }
    }
    public int minimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {
        /*int n = edges1.length + 1;
        List<Integer>[] g = new List[n];
        int ans = 0;
        int a = 0;*/
        int d1 = treeDiameter(/*g, ans, a, */edges1);
        int d2 = treeDiameter(/*g, ans, a, */edges2);
        return Math.max(Math.max(d1, d2), (d1 + 1) / 2 + (d2 + 1) / 2 + 1);
    }
}
