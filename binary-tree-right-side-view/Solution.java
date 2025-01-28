
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
    public List<Integer> rightSideView(TreeNode root) {
        if (root == null) {
            return Collections.emptyList();
        }
        List<Integer> res = new ArrayList<>();
        List<TreeNode> lev = new ArrayList<>();
        lev.add(root);
        while (!lev.isEmpty()) {
            res.add(lev.get(lev.size() - 1).val);
            List<TreeNode> next_lev = new ArrayList<>();
            for (int i = 0; i < lev.size(); ++i) {
                if (lev.get(i).left != null) {
                    next_lev.add(lev.get(i).left);
                }
                if (lev.get(i).right != null) {
                    next_lev.add(lev.get(i).right);
                }
            }
            lev = next_lev;
        }
        return res;
    }
}
