
import java.util.*;

class Solution {
    public int minOperations(int[][] grid, int x) {
        final var n = grid.length;
        final var m = grid[0].length;
        int[] nums = new int[n * m];
        int mod = grid[0][0] % x;
        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < m; ++j) {
                if (grid[i][j] % x != mod) {
                    return -1;
                }
                nums[i * m + j] = grid[i][j];
            }
        }
        Arrays.sort(nums);
        int mid = nums[nums.length / 2];
        int ans = 0;
        for (var num : nums) {
            ans += Math.abs(num - mid) / x;
        }
        return ans;
    }
}
