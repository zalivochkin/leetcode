
class Solution {
    public int maxTotalFruits(int[][] fruits, int startPos, int k) {
        int ans = 0;
        int summ = 0;
        final var n = fruits.length;
        for (int i = 0, j = 0; j < n; ++j) {
            int pj = fruits[j][0];
            int fj = fruits[j][1];
            summ += fj;
            while (i <= j && pj - fruits[i][0] + Math.min(Math.abs(startPos - fruits[i][0]), Math.abs(startPos - pj)) > k) {
                summ -= fruits[i][1];
                ++i;
            }
            ans = Math.max(ans, summ);
        }
        return ans;
    }
}
