
class Solution {
public:
    int numSub(string s) {
        int ans = 0;
        int cnt = 0;
        const int mod = 1e9 + 7;
        for (const auto ch : s) {
            if (ch == '1') {
                ++cnt;
            } else {
                cnt = 0;
            }
            ans = (ans + cnt) % mod;
        }
        return ans;
    }
};
