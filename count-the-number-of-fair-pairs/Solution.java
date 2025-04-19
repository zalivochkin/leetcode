
import java.util.*;

class Solution {
    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums);
        long ans = 0;
        final var n = nums.length;
        for (var i = 0; i < n; ++i) {
            ans += search(nums, upper - nums[i] + 1, i + 1) - search(nums, lower - nums[i], i + 1);
        }
        return ans;
    }

    int search(int[] nums, int x, int left) {
        int right = nums.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
