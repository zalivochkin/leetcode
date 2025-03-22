
import java.util.*;

class Solution {
    public int[] dfs(List<Integer>[] graph, boolean[] visited, int i) {
        visited[i] = true;
        int edgesCnt = 1;
        int nodesCnt = graph[i].size();
        for (var j : graph[i]) {
            if (!visited[j]) {
                var t = dfs(graph, visited, j);
                edgesCnt += t[0];
                nodesCnt += t[1];
            }
        }
        return new int[] {edgesCnt, nodesCnt};
    }

    public int countCompleteComponents(int n, int[][] edges) {
        List<Integer>[] graph;
        boolean[] visited;
        graph = new List[n];
        visited = new boolean[n];
        Arrays.setAll(graph, k -> new ArrayList<>());
        for (var edge : edges) {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }
        int ans = 0;
        for (var i = 0; i < n; ++i) {
            if (!visited[i]) {
                var tmp = dfs(graph, visited, i);
                if (tmp[0] * (tmp[0] - 1) == tmp[1]) {
                    ++ans;
                }
            }
        }
        return ans;
    }
}
