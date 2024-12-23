
import java.util.*;

class Solution {
    class TreeNode {
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

    private int minSwaps(List<Integer> temp) {
        var n = temp.size();
        List<Integer> alls = new ArrayList<>(temp);
        alls.sort((a, b) -> Integer.compare(a, b));
        Map<Integer, Integer> m = new HashMap<>();
        for (var i = 0; i < n; ++i) {
            m.put(alls.get(i), i);
        }
        int[] arr = new int[n];
        for (var i = 0; i < n; ++i) {
            arr[i] = m.get(temp.get(i));
        }
        int ans = 0;
        for (var i = 0; i < n; ++i) {
            while (arr[i] != i) {
                var tmp = arr[arr[i]];
                arr[arr[i]] = arr[i];
                arr[i] = tmp;
                ++ans;
            }
        }
        return ans;
    }

    public int minimumOperations(TreeNode root) {
        Deque<TreeNode> dq = new ArrayDeque<>();
        dq.addLast(root);
        int ans = 0;
        while (!dq.isEmpty()) {
            List<Integer> temp = new ArrayList<>();
            var n = dq.size();
            for (var i = 0; i < n; ++i) {
                TreeNode node = dq.pollFirst();
                temp.add(node.val);
                if (node.left != null) {
                    dq.addLast(node.left);
                }
                if (node.right != null) {
                    dq.addLast(node.right);
                }
            }
            ans += minSwaps(temp);
        }
        return ans;
    }
}
