
import java.util.*;

class Solution {
    public static boolean check(int[] nums, int x, int k) {
        final var n = nums.length;
        int cnt = 0;
        int j = -2;
        for (var i = 0; i < n; ++i) {
            if (nums[i] > x || i == j + 1) {
                continue;
            }
            ++cnt;
            j = i;
        }
        return cnt >= k;
    }

    public int minCapability(int[] nums, int k) {
        int left = 0;
        int right = Arrays.stream(nums).max().getAsInt();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(nums, mid, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
