
class Solution {
    public int[][] divideArray(int[] nums, int k) {
        Arrays.sort(nums);
        final var n = nums.length;
        int[][] ans = new int[n / 3][];
        for (var i = 0; i < n; i += 3) {
            int[] t = Arrays.copyOfRange(nums, i, i + 3);
            if (t[2] - t[0] > k) {
                return new int[][] {};
            }
            ans[i / 3] = t;
        }
        return ans;
    }
}
