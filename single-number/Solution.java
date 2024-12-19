
import java.util.*;

class Solution {
    public int singleNumber(int[] nums) {
        int ans = 0;
        for (var num : nums) {
            ans ^= num;
        }
        return ans;
    }
}
