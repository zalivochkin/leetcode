
import java.util.*;

class Solution {
    public int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        if (n < 2) {
            return 1;
        }
        List<List<Integer>> graph = new ArrayList<>();
        for (var i = 0; i < n; ++i) {
            graph.add(new ArrayList<>());
        }
        int[] degree = new int[n];
        for (var edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
            ++degree[edge[0]];
            ++degree[edge[1]];
        }
        long[] nodeVals = new long[n];
        for (var i = 0; i < n; ++i) {
            nodeVals[i] = values[i];
        }
        Queue<Integer> leafQ = new LinkedList<>();
        for (var i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                leafQ.add(i);
            }
        }
        int compCnt = 0;
        while (!leafQ.isEmpty()) {
            var curr = leafQ.poll();
            --degree[curr];
            long carry = 0;
            if (nodeVals[curr] % k == 0) {
                ++compCnt;
            } else {
                carry = nodeVals[curr];
            }
            for (var nbr : graph.get(curr)) {
                if (degree[nbr] != 0) {
                    --degree[nbr];
                    nodeVals[nbr] += carry;
                    if (degree[nbr] == 1) {
                        leafQ.add(nbr);
                    }
                }
            }
        }
        return compCnt;
    }
}
