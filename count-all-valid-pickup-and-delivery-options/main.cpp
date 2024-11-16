
class Solution {
public:
    int countOrders(int n) {
        const uint64_t mod = 1e9 + 7;
        vector<uint64_t> dp(501);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] * i * (2 * i - 1) % mod;
        }
        return dp[n];
    }
};
