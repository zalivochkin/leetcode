
class Solution {
    public int[] productQueries(int n, int[][] queries) {
        final int MOD = (int) 1e9 + 7;
        int[] powers = new int[Integer.bitCount(n)];
        for (var i = 0; n > 0; ++i) {
            int x = n & -n;
            powers[i] = x;
            n -= x;
        }
        int[] ans = new int[queries.length];
        final var m = ans.length;
        for (var i = 0; i < m; ++i) {
            long x = 1;
            int l = queries[i][0], r = queries[i][1];
            for (var j = l; j <= r; ++j) {
                x = (x * powers[j]) % MOD;
            }
            ans[i] = (int) x;
        }
        return ans;
    }
}
