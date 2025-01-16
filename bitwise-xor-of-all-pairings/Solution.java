
import java.util.*;

class Solution {
    public int xorAllNums(int[] nums1, int[] nums2) {
        int res = 0;
        if (nums2.length % 2 == 1) {
            for (var num : nums1) {
                res ^= num;
            }
        }
        if (nums1.length % 2 == 1) {
            for (var num : nums2) {
                res ^= num;
            }
        }
        return res;
    }
}
