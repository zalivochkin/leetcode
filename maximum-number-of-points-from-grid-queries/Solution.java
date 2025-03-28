
import java.util.*;

class Solution {
    public int[] maxPoints(int[][] grid, int[] queries) {
        int l = queries.length;
        int[][] qs = new int[l][2];
        for (var i = 0; i < l; ++i) {
            qs[i] = new int[] {queries[i], i};
        }
        Arrays.sort(qs, (a, b) -> a[0] - b[0]);
        int[] ans = new int[l];
        int n = grid.length;
        int m = grid[0].length;
        boolean[][] vis = new boolean[n][m];
        vis[0][0] = true;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[] {grid[0][0], 0, 0});
        int[] dirs = new int[] {-1, 0, 1, 0, -1};
        int cnt = 0;
        for (var e : qs) {
            int v = e[0];
            int k = e[1];
            while (!pq.isEmpty() && pq.peek()[0] < v) {
                var p = pq.poll();
                ++cnt;
                for (var h = 0; h < 4; ++h) {
                    int ih = p[1] + dirs[h];
                    int jh = p[2] + dirs[h + 1];
                    if (ih >= 0 && ih < n && jh >= 0 && jh < m && !vis[ih][jh]) {
                        vis[ih][jh] = true;
                        pq.offer(new int[] {grid[ih][jh], ih, jh});
                    }
                }
            }
            ans[k] = cnt;
        }
        return ans;
    }
}
