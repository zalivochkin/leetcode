
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
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        if (root == null) {
            return ans;
        }
        Deque<TreeNode> dq = new ArrayDeque<>();
        dq.addLast(root);
        while (!dq.isEmpty()) {
            var maxVal = Integer.MIN_VALUE;
            var n = dq.size();
            for (var i = 0; i < n; ++i) {
                TreeNode node = dq.pollFirst();
                maxVal = Math.max(maxVal, node.val);
                if (node.left != null) {
                    dq.addLast(node.left);
                }
                if (node.right != null) {
                    dq.addLast(node.right);
                }
            }
            ans.add(maxVal);
        }
        return ans;
    }
}
