
import java.util.*;

class Solution {
    public int countPaths(int n, int[][] roads) {
        final long inf = Long.MAX_VALUE / 2;
        final int mod = (int) 1e9 + 7;
        long[][] graph = new long[n][n];
        for (var edge : graph) {
            Arrays.fill(edge, inf);
        }
        for (var road : roads) {
            graph[road[0]][road[1]] = road[2];
            graph[road[1]][road[0]] = road[2];
        }
        graph[0][0] = 0;
        long[] dist = new long[n];
        Arrays.fill(dist, inf);
        dist[0] = 0;
        long[] dp = new long[n];
        dp[0] = 1;
        boolean[] visited = new boolean[n];
        for (var i = 0; i < n; ++i) {
            int t = -1;
            for (var j = 0; j < n; ++j) {
                if (!visited[j] && (t == -1 || dist[j] < dist[t])) {
                    t = j;
                }
            }
            visited[t] = true;
            for (var j = 0; j < n; ++j) {
                if (j == t) {
                    continue;
                }
                long ne = dist[t] + graph[t][j];
                if (dist[j] > ne) {
                    dist[j] = ne;
                    dp[j] = dp[t];
                } else if (dist[j] == ne) {
                    dp[j] = (dp[j] + dp[t]) % mod;
                }
            }
        }
        return (int) dp[n - 1];
    }
}
