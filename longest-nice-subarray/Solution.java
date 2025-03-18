
class Solution {
    public int longestNiceSubarray(int[] nums) {
        final int n = nums.length;
        int mask = 0;
        int ans = 0;
        for(int lft = 0, rght = 0; rght < n; ++rght) {
            while((mask & nums[rght]) != 0) {
                mask = mask ^ nums[lft];
                ++lft;
            }
            mask |= nums[rght];
            ans = Math.max(ans, rght - lft + 1);
        }
        return ans;
    }
}
