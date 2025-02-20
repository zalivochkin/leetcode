
import java.util.*;

class Solution {
    public String findDifferentBinaryString(String[] nums) {
        int mask = 0;
        for (var num : nums) {
            int cnt = 0;
            for (var i = 0; i < num.length(); ++i) {
                if (num.charAt(i) == '1') {
                    ++cnt;
                }
            }
            mask |= 1 << cnt;
        }
        for (var i = 0;; ++i) {
            if ((mask >> i & 1) == 0) {
                return "1".repeat(i) + "0".repeat(nums.length - i);
            }
        }
    }
}
