
class Solution {
    public int subsetXORSum(int[] nums) {
        int sum = 0;
        final var n = nums.length;
        for (var i = 0; i < 1 << n; ++i) {
            var xorSum = 0;
            for (var j = 0; j < n; ++j) {
                if ((i & (1 << j)) != 0) {
                    xorSum ^= nums[j];
                }
            }
            sum += xorSum;
        }
        return sum;
    }
}
