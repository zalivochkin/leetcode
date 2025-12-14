
class Solution {
public:
    int numberOfWays(string corridor) {
        const int mod = 1e9 + 7;
        long long ans = 1;
        int cnt = 0;
        int last = 0;
        const auto n = corridor.length();
        for (auto i = 0; i < n; ++i) {
            if (corridor[i] == 'S') {
                if (++cnt > 2 && cnt % 2) {
                    ans = ans * (i - last) % mod;
                }
                last = i;
            }
        }
        return cnt > 0 && cnt % 2 == 0 ? ans : 0;
    }
};
