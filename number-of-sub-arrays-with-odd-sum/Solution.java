
class Solution {
    public int numOfSubarrays(int[] arr) {
        final int mod = (int) 1e9 + 7;
        int[] cnt = {1, 0};
        int ans = 0;
        int summ = 0;
        for (var x : arr) {
            summ += x;
            ans += cnt[summ & 1 ^ 1];
            ans %= mod;
            cnt[summ & 1] += 1;
        }
        return ans;
    }
}
