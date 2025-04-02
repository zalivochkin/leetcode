
class Solution {
    public long maximumTripletValue(int[] nums) {
        long ans = 0;
        int mx = 0;
        int mxDiff = 0;
        for (var num : nums) {
            ans = Math.max(ans, (long) mxDiff * num);
            mx = Math.max(mx, num);
            mxDiff = Math.max(mxDiff, mx - num);
        }
        return ans;
    }
}
