import java.util.*;

public class Solution {
    public int maximumBeauty(int[] nums, int k) {
        Map<Integer, Integer> cnts = new TreeMap<>();
        for (var num : nums) {
            cnts.put(num, cnts.getOrDefault(num, 0) + 1);
            cnts.put(num + k * 2 + 1, cnts.getOrDefault(num + k * 2 + 1, 0) - 1);
        }
        int summ = 0;
        int res = 0;
        for (var cnt : cnts.values()) {
            summ += cnt;
            res = Math.max(res, summ);
        }
        return res;
    }
}
