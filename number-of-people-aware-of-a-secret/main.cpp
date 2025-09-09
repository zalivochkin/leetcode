
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int mod = 1e9 + 7;
        int m = (n << 1) + 10;
        vector<long long> dp(m);
        vector<long long> cnt(m);
        cnt[1] = 1;
        for (int i = 1; i <= n; ++i) {
            if (!cnt[i]) {
                continue;
            }
            dp[i] = (dp[i] + cnt[i]) % mod;
            dp[i + forget] = (dp[i + forget] - cnt[i] + mod) % mod;
            int nxt = i + delay;
            while (nxt < i + forget) {
                cnt[nxt] = (cnt[nxt] + cnt[i]) % mod;
                ++nxt;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = (ans + dp[i]) % mod;
        }
        return ans;
    }
};
