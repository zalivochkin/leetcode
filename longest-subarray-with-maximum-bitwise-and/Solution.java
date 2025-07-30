
class Solution {
    public int longestSubarray(int[] nums) {
        int mx = 0;
        for (var num : nums) {
            mx = Math.max(mx, num);
        }
        int ans = 0;
        int cnt = 0;
        for (var num : nums) {
            if (num == mx) {
                ++cnt;
                ans = Math.max(ans, cnt);
            } else {
                cnt = 0;
            }
        }
        return ans;
    }
}
