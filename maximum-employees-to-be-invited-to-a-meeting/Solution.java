
import java.util.*;

class Solution {
    public int maximumInvitations(int[] favorite) {
        return Math.max(maxCycle(favorite), topologicalSort(favorite));
    }

    private int maxCycle(int[] favorite) {
        final var n = favorite.length;
        var visited = new boolean[n];
        int res = 0;
        int j;
        for (var i = 0; i < n; ++i) {
            if (!visited[i]) {
                List<Integer> cycle = new ArrayList<>();
                j = i;
                while (!visited[j]) {
                    cycle.add(j);
                    visited[j] = true;
                    j = favorite[j];
                }
                for (var k = 0; k < cycle.size(); ++k) {
                    if (cycle.get(k) == j) {
                        res = Math.max(res, cycle.size() - k);
                    }
                }
            }
        }
        return res;
    }

    private int topologicalSort(int[] favorite) {
        final var n = favorite.length;
        var indeg = new int[n];
        var dist = new int[n];
        Arrays.fill(dist, 1);
        for (var fav : favorite) {
            indeg[fav] += 1;
        }
        Deque<Integer> dq = new ArrayDeque<>();
        for (var i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                dq.offer(i);
            }
        }
        int res = 0;
        int i;
        while (!dq.isEmpty()) {
            i = dq.pollFirst();
            dist[favorite[i]] = Math.max(dist[favorite[i]], dist[i] + 1);
            indeg[favorite[i]] -= 1;
            if (indeg[favorite[i]] == 0) {
                dq.offer(favorite[i]);
            }
        }
        for (i = 0; i < n; ++i) {
            if (i == favorite[favorite[i]]) {
                res += dist[i];
            }
        }
        return res;
    }
}
