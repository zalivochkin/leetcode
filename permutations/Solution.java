
import java.util.*;

class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        if (nums.length == 1) {
            ans.add(new ArrayList<>(List.of(nums[0])));
        } else {
            for (var i = 0; i < nums.length; ++i) {
                int[] subNums = new int[nums.length - 1];
                int k = 0;
                for (var j = 0; j < nums.length; ++j) {
                    if (j != i) {
                        subNums[k] = nums[j];
                        ++k;
                    }
                }
                List<List<Integer>> subAns = permute(subNums);
                for (var subA : subAns) {
                    subA.add(0, nums[i]);
                    ans.add(subA);
                }
            }
        }
        return ans;
    }
}
