
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
    public TreeNode recoverFromPreorder(String traversal) {
        final var n = traversal.length();
        Stack<TreeNode> st = new Stack<>();
        int depth = 0;
        int num = 0;
        for (var i = 0; i < n; ++i) {
            if (traversal.charAt(i) == '-') {
                depth++;
            } else {
                num = 10 * num + traversal.charAt(i) - '0';
            }
            if (i + 1 >= n || (Character.isDigit(traversal.charAt(i)) && traversal.charAt(i + 1) == '-')) {
                TreeNode newNode = new TreeNode(num);
                while (st.size() > depth) {
                    st.pop();
                }
                if (!st.empty()) {
                    if (st.peek().left == null) {
                        st.peek().left = newNode;
                    } else {
                        st.peek().right = newNode;
                    }
                }
                st.push(newNode);
                depth = 0;
                num = 0;
            }
        }
        TreeNode res = null;
        while (!st.empty()) {
            res = st.pop();
        }
        return res;
    }
}
