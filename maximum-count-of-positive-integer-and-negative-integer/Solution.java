
class Solution {
    public int maximumCount(int[] nums) {
        int a = 0;
        int b = 0;
        for (var num : nums) {
            if (num > 0) {
                ++a;
            } else if (num < 0) {
                ++b;
            }
        }
        return Math.max(a, b);
    }
}
