
class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);
        long ans = 0;
        final var n = happiness.length;
        for (int i = 0; i < k; ++i) {
            int x = happiness[n - i - 1] - i;
            ans += Math.max(x, 0);
        }
        return ans;
    }
}
