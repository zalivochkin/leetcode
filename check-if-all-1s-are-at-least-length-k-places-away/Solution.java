
class Solution {
    public boolean kLengthApart(int[] nums, int k) {
        int j = -(k + 1);
        final var n = nums.length;
        for (var i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                if (i - j - 1 < k) {
                    return false;
                }
                j = i;
            }
        }
        return true;
    }
}
