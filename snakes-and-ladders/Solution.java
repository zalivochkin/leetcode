
import javax.swing.*;
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

    public int snakesAndLadders(int[][] board) {
        final var n = board.length;
        final var m = n * n;
        boolean[] visited = new boolean[m + 1];
        visited[1] = true;
        Queue<Integer> q = new ArrayDeque<>();
        q.add(1);
        int res = 0;
        while (!q.isEmpty()) {
            int sz = q.size();
            while (sz > 0) {
                int lbl = q.poll();
                if (lbl == m) {
                    return res;
                }
                for (int j = lbl + 1; j <= Math.min(lbl + 6, m); ++j) {
                    int integ = (j - 1) / n;
                    int reminder = (j - 1) % n;
                    if (integ % 2 == 1) {
                        reminder = n - reminder - 1;
                    }
                    integ = n - integ - 1;
                    int target_lbl = j;
                    if (board[integ][reminder] != -1) {
                        target_lbl = board[integ][reminder];
                    }
                    if (!visited[target_lbl]) {
                        visited[target_lbl] = true;
                        q.add(target_lbl);
                    }
                }
                --sz;
            }
            ++res;
        }
        return -1;
    }
}
