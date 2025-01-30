
import java.util.*;

class Solution {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public int[] calcHeight(int i, int[] dist, List<Integer>[] mapEdges) {
        int[] res = new int[2];
        Deque<Integer> dq = new ArrayDeque<>();
        dq.offer(i);
        Arrays.fill(dist, 0);
        dist[i] = 1;
        res[1] = 1;
        res[0] = i;
        while (!dq.isEmpty()) {
            int node1 = dq.poll();
            res[0] = Math.min(res[0], node1);
            for (int node2 : mapEdges[node1]) {
                if (dist[node2] == 0) {
                    dist[node2] = dist[node1] + 1;
                    res[1] = Math.max(res[1], dist[node2]);
                    dq.offer(node2);
                } else if (Math.abs(dist[node2] - dist[node1]) != 1) {
                    res[0] = -1;
                    return res;
                }
            }
        }
        return res;
    }

    public int magnificentSets(int n, int[][] edges) {
        List<Integer>[] mapEdges = new List[n];
        Arrays.setAll(mapEdges, mapEdge -> new ArrayList<>());
        for (var edge : edges) {
            int node1 = edge[0] - 1;
            int node2 = edge[1] - 1;
            mapEdges[node1].add(node2);
            mapEdges[node2].add(node1);
        }
        int[] d = new int[n];
        int[] dist = new int[n];
        for (var i = 0; i < n; ++i) {
            int[] res = calcHeight(i, dist, mapEdges);
            if (res[0] == -1) {
                return -1;
            }
            d[res[0]] = Math.max(d[res[0]], res[1]);
        }
        return Arrays.stream(d).sum();
    }
}
