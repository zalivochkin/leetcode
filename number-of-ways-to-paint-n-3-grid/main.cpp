
class Solution {
public:
    int numOfWays(int n) {
        uint64_t mod = 1e9 + 7;
        uint64_t pattern_121 = 6;
        uint64_t pattern_123 = 6;
        uint64_t pattern_121_;
        for (int i = 1; i < n; ++i) {
            pattern_121_ = pattern_121;
            pattern_121 = (pattern_121 * 3 + pattern_123 * 2) % mod;
            pattern_123 = (pattern_121_ * 2 + pattern_123 * 2) % mod;
        }
        return (pattern_121 + pattern_123) % mod;
    }
};
