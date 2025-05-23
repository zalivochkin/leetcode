
class Solution {
    public long maximumValueSum(int[] nums, int k, int[][] edges) {
        long f0 = 0;
        long f1 = -0x3f3f3f3f;
        for (var num : nums) {
            long tmp = f0;
            f0 = Math.max(f0 + num, f1 + (num ^ k));
            f1 = Math.max(f1 + num, tmp + (num ^ k));
        }
        return f0;
    }
}
