
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
    int global_k = 0;
    int res = 0;
    public void dfs(TreeNode root) {
        if (global_k <= 0) {
            return;
        }
        if (root.left != null) {
            dfs(root.left);
        }
        --global_k;
        if (global_k == 0) {
            res = root.val;
        }
        if (root.right != null) {
            dfs(root.right);
        }
    }
    public int kthSmallest(TreeNode root, int k) {
        global_k = k;
        dfs(root);
        return res;
    }
}
