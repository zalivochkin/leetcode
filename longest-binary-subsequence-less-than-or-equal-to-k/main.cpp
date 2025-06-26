
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int ans = 0;
        int v = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                ++ans;
            } else if (ans < 30 && (v | 1 << ans) <= k) {
                v |= 1 << ans;
                ++ans;
            }
        }
        return ans;
    }
};
