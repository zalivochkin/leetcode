
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int takeCharacters(string s, int k) {
        const auto n = s.size();
        vector<int> cnts(3, 0);
        for (auto i = 0; i < n; ++i) {
            cnts[s[i] - 'a'] += 1;
        }
        for (const auto cnt: cnts) {
            if (cnt < k) {
                return -1;
            }
        }
        auto res = n;
        auto j = n - n;
        for (auto i = 0; i < n; ++i) {
            cnts[s[i] - 'a'] -= 1;
            for (; j < n && cnts[s[i] - 'a'] < k; ++j) {
                cnts[s[j] - 'a'] += 1;
            }
            res = min(res, n - (i - j + 1));
        }
        return static_cast<int>(res);
    }
};
