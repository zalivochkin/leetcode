
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
    public List<Double> averageOfLevels(TreeNode root) {
        ArrayList<TreeNode> curLevel = new ArrayList<>();
        ArrayList<TreeNode> nextLevel = new ArrayList<>();
        curLevel.add(root);
        List<Double> ans = new ArrayList<>();
        while (!curLevel.isEmpty()) {
            nextLevel = new ArrayList<>();
            Double avg = 0.0;
            for (var i = 0; i < curLevel.size(); ++i) {
                avg += curLevel.get(i).val;
                if (curLevel.get(i).left != null) {
                    nextLevel.add(curLevel.get(i).left);
                }
                if (curLevel.get(i).right != null) {
                    nextLevel.add(curLevel.get(i).right);
                }
            }
            ans.add(avg / curLevel.size());
            curLevel = nextLevel;
        }
        return ans;
    }
}
