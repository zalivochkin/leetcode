
import java.util.*;

class Solution {
    public int minTimeToReach(int[][] moveTime) {
        final var n = moveTime.length;
        final var m = moveTime[0].length;
        int[][] dist = new int[n][m];
        for (var row : dist) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        dist[0][0] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[] {0, 0, 0});
        int[] dirs = {-1, 0, 1, 0, -1};
        while (true) {
            int[] p = pq.poll();
            int d = p[0];
            int i = p[1];
            int j = p[2];
            if (i == n - 1 && j == m - 1) {
                return d;
            }
            if (d > dist[i][j]) {
                continue;
            }
            for (var k = 0; k < 4; k++) {
                int ik = i + dirs[k];
                int jk = j + dirs[k + 1];
                if (ik >= 0 && ik < n && jk >= 0 && jk < m) {
                    int t = Math.max(moveTime[ik][jk], dist[i][j]) + 1;
                    if (dist[ik][jk] > t) {
                        dist[ik][jk] = t;
                        pq.offer(new int[] {t, ik, jk});
                    }
                }
            }
        }
    }
}
