
import java.util.*;

class Solution {
    public TreeNode prev = null;
    public boolean dfs(TreeNode root) {
        if (root == null) {
            return true;
        }
        if (!dfs(root.left)) {
            return false;
        }
        if (prev != null && prev.val >= root.val) {
            return false;
        }
        prev = root;
        return dfs(root.right);
    }

    public boolean isValidBST(TreeNode root) {
        return dfs(root);
    }
}
