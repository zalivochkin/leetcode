
class Solution {
    public boolean isZeroArray(int[] nums, int[][] queries) {
        final var n = nums.length;
        int[] diff = new int[n + 1];
        for (var query : queries) {
            diff[query[0]]++;
            diff[query[1] + 1]--;
        }
        int current = 0;
        for (var i = 0; i < n; i++) {
            current += diff[i];
            if (nums[i] > current) {
                return false;
            }
        }
        return true;
    }
}
