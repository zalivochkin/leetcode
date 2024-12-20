
import java.util.*;

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

class Solution {
    public TreeNode reverseOddLevels(TreeNode root) {
        if (root == null) {
            return null;
        }
        Deque<TreeNode> dq = new ArrayDeque<>();
        dq.push(root);
        int level = 0;
        while (!dq.isEmpty()) {
            int size = dq.size();
            Stack<Integer> stack = new Stack<>();
            List<TreeNode> list = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                var node = dq.peekFirst();
                stack.add(node.val);
                if (node.left != null) {
                    dq.addLast(node.left);
                }
                if (node.right != null) {
                    dq.addLast(node.right);
                }
                list.add(node);
                dq.removeFirst();
            }
            if (level % 2 != 0) {
                for (TreeNode treeNode : list) {
                    treeNode.val = stack.peek();
                    stack.pop();
                }
            }
            ++level;
        }
        return root;
    }
}
