
class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        int[] cnt = new int[100];
        int ans = 0;
        for (var domino : dominoes) {
            int x = domino[0] < domino[1] ? domino[0] * 10 + domino[1] : domino[1] * 10 + domino[0];
            ans += cnt[x];
            cnt[x] += 1;
        }
        return ans;
    }
}
