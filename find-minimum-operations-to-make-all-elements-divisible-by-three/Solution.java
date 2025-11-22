
class Solution {
    public int minimumOperations(int[] nums) {
        int ans = 0;
        for (final var num : nums) {
            int mod = num % 3;
            if (mod != 0) {
                ans += Math.min(mod, 3 - mod);
            }
        }
        return ans;
    }
}
