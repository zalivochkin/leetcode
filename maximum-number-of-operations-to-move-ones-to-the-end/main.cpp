
class Solution {
public:
    int maxOperations(string s) {
        int ans = 0;
        int cnt = 0;
        const auto n = s.size();
        for (auto i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++cnt;
            } else if (i && s[i - 1] == '1') {
                ans += cnt;
            }
        }
        return ans;
    }
};
