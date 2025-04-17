
class Solution {
    public int countPairs(int[] nums, int k) {
        int count = 0;
        final var n = nums.length;
        for (var i = 0; i < n; i++) {
            for (var j = i + 1; j < n; j++) {
                if (nums[i] == nums[j] && (i * j) % k == 0) {
                    count++;
                }
            }
        }
        return count;
    }
}
