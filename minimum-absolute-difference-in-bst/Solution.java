
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
    ArrayList<Integer> sortedVals = new ArrayList<>();
    void dsf(TreeNode root) {
        if (root.left != null) {
            dsf(root.left);
        }
        sortedVals.add(root.val);
        if (root.right != null) {
            dsf(root.right);
        }
    }
    public int getMinimumDifference(TreeNode root) {
        dsf(root);
        int minDiff = Integer.MAX_VALUE;
        for (var i = 1; i < sortedVals.size(); ++i) {
            minDiff = Math.min(minDiff, sortedVals.get(i) - sortedVals.get(i - 1));
        }
        return minDiff;
    }
}
