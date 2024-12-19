
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
    public TreeNode sortedArrayToBST(int[] nums) {
        if (nums.length == 1) {
            return new TreeNode(nums[0]);
        } else if (nums.length == 2) {
            return new TreeNode(nums[1], new TreeNode(nums[0]), null);
        } else if (nums.length == 2) {
            return new TreeNode(nums[1], new TreeNode(nums[0]), new TreeNode(nums[2]));
        }
        int midIndx = nums.length / 2;
        int[] leftNums = new int[midIndx];
        for (int i = 0; i < midIndx; ++i) {
            leftNums[i] = nums[i];
        }
        int[] rightNums = new int[nums.length - midIndx - 1];
        for (int i = 0; i < nums.length - midIndx - 1; ++i) {
            rightNums[i] = nums[midIndx + i + 1];
        }
        return new TreeNode(nums[midIndx], sortedArrayToBST(leftNums), sortedArrayToBST(rightNums));
    }
}
