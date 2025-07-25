
import java.util.*;

class Solution {
    public int maxSum(int[] nums) {
        Arrays.sort(nums);
        if (nums[nums.length - 1] < 0) {
            return nums[nums.length - 1];
        }
        Set<Integer> visited = new HashSet<>();
        int sum = 0;
        for (int i = nums.length - 1; i >= 0; i--) {
            if (nums[i] > 0 && !visited.contains(nums[i])) {
                sum += nums[i];
                visited.add(nums[i]);
            }
        }
        return sum;
    }
}
