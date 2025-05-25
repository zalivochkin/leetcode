
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> cnt;
        for (const auto &w : words) {
            cnt[w] += 1;
        }
        int ans = 0;
        int x = 0;
        for (const auto& [k, v] : cnt) {
            string rk = k;
            ranges::reverse(rk);
            if (k[0] == k[1]) {
                x += v & 1;
                ans += v / 2 * 2 * 2;
            } else if (cnt.contains(rk)) {
                ans += min(v, cnt[rk]) * 2;
            }
        }
        ans += x ? 2 : 0;
        return ans;
    }
};
