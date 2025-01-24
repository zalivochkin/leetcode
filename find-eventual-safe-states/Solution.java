
import java.util.*;

class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        var n = graph.length;
        var indeg = new int[n];
        List<Integer>[] rg = new List[n];
        Arrays.setAll(rg, k -> new ArrayList<>());
        Deque<Integer> dq = new ArrayDeque<>();
        for (var i = 0; i < n; ++i) {
            for (var j : graph[i]) {
                rg[j].add(i);
            }
            indeg[i] = graph[i].length;
            if (indeg[i] == 0) {
                dq.offer(i);
            }
        }
        while (!dq.isEmpty()) {
            var i = dq.pollFirst();
            for (var j : rg[i]) {
                indeg[j] -= 1;
                if (indeg[j] == 0) {
                    dq.offer(j);
                }
            }
        }
        List<Integer> res = new ArrayList<>();
        for (var i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                res.add(i);
            }
        }
        return res;
    }
}
