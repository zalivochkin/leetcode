
import java.util.*;

class Solution {
    public int searchInsert(int[] nums, int target) {
        int leftIndx = 0;
        int rightIndx = nums.length - 1;
        while (rightIndx >= leftIndx) {
            int midIndx = leftIndx + (rightIndx - leftIndx) / 2;
            if (nums[midIndx] == target) {
                return midIndx;
            } else if (nums[midIndx] > target) {
                rightIndx = midIndx - 1;
            } else {
                leftIndx = midIndx + 1;
            }
        }
        return leftIndx;
    }
}
