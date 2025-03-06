
class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        final var n = grid.length;
        int[] cnt = new int[n * n + 1];
        int[] ans = new int[2];
        for (var row : grid) {
            for (var x : row) {
                if (++cnt[x] == 2) {
                    ans[0] = x;
                }
            }
        }
        int x = 1;
        while (true) {
            if (cnt[x] == 0) {
                ans[1] = x;
                return ans;
            }
            ++x;
        }
    }
}
