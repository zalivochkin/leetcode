
import java.util.*;

class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> ans = new ArrayList<>();
        if (nums.length == 0) {
            return ans;
        }
        if (nums.length == 1) {
            ans.add(Integer.valueOf(nums[0]).toString());
            return ans;
        }
        int start = 0;
        for (var i = 1; i < nums.length; ++i) {
            if (nums[i] - 1 != nums[i - 1]) {
                if (i - 1 == start) {
                    ans.add(Integer.valueOf(nums[start]).toString());
                } else {
                    ans.add(Integer.valueOf(nums[start]).toString() + "->" + Integer.valueOf(nums[i - 1]).toString());
                }
                start = i;
            }
            if (i == nums.length - 1) {
                if (nums[i] - 1 != nums[i - 1]) {
                    ans.add(Integer.valueOf(nums[i]).toString());
                } else {
                    ans.add(Integer.valueOf(nums[start]).toString() + "->" + Integer.valueOf(nums[i]).toString());
                }
            }
        }
        return ans;
    }
}
