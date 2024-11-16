
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int mod = 1e9 + 7;
        int sz = max(zero, one);
        vector<long long> dp(sz + 1);
        dp[0] = 1;
        long long ans = 0;
        for (int x = 1; x <= min(zero, one) + 1; x++) {
            long long su = 0;
            vector<long long> ndp(sz + 1);
            for (int j = x; j <= sz; j++) {
                su += dp[j - 1];
                if (j >= limit + 1) su -= dp[j - limit - 1];
                su += mod, su %= mod;
                ndp[j] = su;
            }
            ans += ndp[zero] * dp[one] + ndp[zero] * ndp[one];
            ans += ndp[one] * dp[zero] + ndp[one] * ndp[zero];
            ans %= mod;
            dp = move(ndp);
        }
        return ans;
    }
};
