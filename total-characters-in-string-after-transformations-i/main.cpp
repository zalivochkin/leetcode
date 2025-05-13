
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> cnt(26, 0);
        for (auto ch : s) {
            cnt[ch - 'a'] += 1;
        }
        int MOD = 1000000007;
        vector<int> nxt(26);
        for (int round = 0; round < t; ++round) {
            ranges::fill(nxt, 0);
            nxt[0] = cnt[25];
            nxt[1] = (cnt[25] + cnt[0]) % MOD;
            for (int i = 2; i < 26; ++i) {
                nxt[i] = cnt[i - 1];
            }
            swap(cnt, nxt);
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + cnt[i]) % MOD;
        }
        return ans;
    }
};
