
class Solution {
    public long maximumTripletValue(int[] nums) {
        long max = 0;
        long maxDiff = 0;
        long ans = 0;
        for (var num : nums) {
            ans = Math.max(ans, num * maxDiff);
            max = Math.max(max, num);
            maxDiff = Math.max(maxDiff, max - num);
        }
        return ans;
    }
}
