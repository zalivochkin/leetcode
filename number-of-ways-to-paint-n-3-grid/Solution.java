
class Solution {
    public int numOfWays(int n) {
        int mod = (int) 1e9 + 7;
        long pattern_121 = 6;
        long pattern_123 = 6;
        long pattern_121_;
        for (int i = 1; i < n; ++i) {
            pattern_121_ = pattern_121;
            pattern_121 = (pattern_121 * 3 + pattern_123 * 2) % mod;
            pattern_123 = (pattern_121_ * 2 + pattern_123 * 2) % mod;
        }
        return (int) (pattern_121 + pattern_123) % mod;
    }
}
